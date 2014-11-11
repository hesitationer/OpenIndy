#include "geometry.h"

#include "coordinatesystem.h"
#include "observation.h"
#include "station.h"
#include "function.h"

Geometry::Geometry(bool isNominal, QObject *parent) : Feature(parent),
    myActual(NULL), myNominalCoordSys(NULL), isNominal(isNominal)
{
}

Geometry::~Geometry(){

    if(this->isNominal){
        //delete this geometry from the nominal list of its actual
        if(this->myActual != NULL){
            int index = -1;
            int k = 0;
            foreach(Geometry *checkNominal, this->myActual->nominals){
                if(checkNominal != NULL && checkNominal->id == this->id){
                    index = k;
                    break;
                }
                k++;
            }
            if(index >= 0){
                this->myActual->nominals.removeAt(index);
            }
        }

        //delete this geometry from list of nominals in myNominalCoordSys
        if(this->myNominalCoordSys != NULL){
            this->myNominalCoordSys->removeNominal(this);
        }
    }else{
        //delete observations that only belong to this geometry
        for(int i = 0; i < this->myObservations.size(); i++){
            Observation *myObs = this->myObservations.at(i);
            if(myObs->myTargetGeometries.size() == 1){
                Station *myStation = myObs->myStation;
                if(myStation != NULL && myStation->coordSys != NULL){
                    //myStation->coordSys->getObservations().removeOne(myObs);
                }
            }
            delete myObs;
        }

        //delete property myActual from all nominal geometries which belong to this actual geometry
        foreach(Geometry *checkNominal, this->nominals){
            if(checkNominal != NULL){
                checkNominal->myActual = NULL;
            }
        }
    }

}

/*!
 * \brief Geometry::getIsCommon
 * \return
 */
bool Geometry::getIsCommon() const{
    return this->isCommon;
}

/*!
 * \brief Geometry::setCommonState
 * \param isCommon
 */
void Geometry::setCommonState(bool isCommon){
    if(this->isCommon != isCommon){
        this->isCommon = isCommon;
        emit this->geomIsCommonChanged(this->id);
    }
}

/*!
 * \brief Geometry::getIsNominal
 * \return
 */
bool Geometry::getIsNominal() const{
    return this->isNominal;
}

/*!
 * \brief Geometry::getMyNominals
 * \return
 */
QList<Geometry *> Geometry::getMyNominals() const{
    return this->nominals;
}

/*!
 * \brief Geometry::addNominal
 * \param myNominal
 * \return
 */
bool Geometry::addNominal(Geometry *myNominal){
    if(!this->isNominal && myNominal != NULL && myNominal->getIsNominal()){
        this->nominals.append(myNominal);
        emit this->geomMyNominalsChanged(this->id);
        return true;
    }
    return false;
}

/*!
 * \brief Geometry::removeNominal
 * \param myNominal
 * \return
 */
bool Geometry::removeNominal(Geometry *myNominal){
    if(!this->isNominal && myNominal != NULL && myNominal->getIsNominal()){
        for(unsigned int i = 0; i < this->nominals.size(); i++){
            if(this->nominals.at(i) != NULL && this->nominals.at(i)->getId() == myNominal->getId()){
                this->nominals.removeAt(i);
                emit this->geomMyNominalsChanged(this->id);
                return true;
            }
        }
    }
    return false;
}

/*!
 * \brief Geometry::getMyActual
 * \return
 */
Geometry *Geometry::getMyActual() const{
    return this->myActual;
}

/*!
 * \brief Geometry::setMyActual
 * \param myActual
 * \return
 */
bool Geometry::setMyActual(Geometry *myActual){
    if(this->isNominal && myActual != NULL && !myActual->getIsNominal()){
        if(this->myActual != NULL && this->myActual->getId() == myActual->getId()){
            return false;
        }else{
            this->myActual = myActual;
            emit this->geomMyActualChanged(this->id);
            return true;
        }
    }else if(myActual == NULL && this->myActual != NULL){
        this->myActual = NULL;
        emit this->geomMyActualChanged(this->id);
        return true;
    }
    return false;
}

/*!
 * \brief Geometry::getObservations
 * \return
 */
QList<Observation *> Geometry::getObservations() const{
    return this->myObservations;
}

/*!
 * \brief Geometry::addObservation
 * \param obs
 * \return
 */
bool Geometry::addObservation(Observation *obs){
    if(!this->isNominal && obs != NULL){
        this->myObservations.append(obs);
        emit this->geomMyObservationsChanged(this->id);
        return true;
    }
    return false;
}

/*!
 * \brief Geometry::removeObservation
 * \param obs
 * \return
 */
bool Geometry::removeObservation(Observation *obs){
    if(!this->isNominal && obs != NULL){
        for(int i = 0; i < this->myObservations.size(); i++){
            if(this->myObservations.at(i)->getId() == obs->getId()){

                this->myObservations.removeAt(i);

                foreach(Function *myFunc, this->getFunctions()){
                    if(myFunc != NULL){
                        myFunc->removeObservation(this->id);
                    }
                }

                emit this->geomMyObservationsChanged(this->id);
                return true;

            }
        }
        return true;
    }
    return false;
}

/*!
 * \brief Geometry::getNominalSystem
 * \return
 */
CoordinateSystem *Geometry::getNominalSystem() const{
    return this->myNominalCoordSys;
}

/*!
 * \brief Geometry::setNominalSystem
 * \param nomSys
 * \return
 */
bool Geometry::setNominalSystem(CoordinateSystem *nomSys){
    if(this->isNominal && nomSys != NULL){
        this->myNominalCoordSys = nomSys;
        emit this->geomMyNominalSystemChanged(this->id);
        return true;
    }
    return false;
}

/*!
 * \brief getDisplayObs displays the number of current valid observations and total observations in the gui.
 * Display style x/y where x is current valid and y is total observation count.
 * \return
 */
QString Geometry::getDisplayObs() const
{
    int validObs = 0;
    int totalObs = this->myObservations.size();
    for(int i=0;i<totalObs;i++){
        if(this->myObservations.at(i)->isValid){
            validObs += 1;
        }
    }
    return QString(QString::number(validObs)+"/"+QString::number(totalObs));
	
}

void Geometry::insertReadingType(Configuration::ReadingTypes readingType, QString displayName){

    QMap<Configuration::ReadingTypes,QString>::const_iterator i = usedReadingTypes.find(readingType);

    if (i != usedReadingTypes.end() && i.key() != readingType) {
        usedReadingTypes.insert(readingType,displayName);
    }

    emit this->geomUsedReadingTypesChanged(this->id);
}

/*!
 * \brief Geometry::getMeasurementConfig
 * \return
 */
MeasurementConfig Geometry::getMeasurementConfig() const{
    return this->mConfig;
}

/*!
 * \brief Geometry::setMeasurementConfig
 * \param myConfig
 */
void Geometry::setMeasurementConfig(MeasurementConfig myConfig){
    this->mConfig = myConfig;
    emit this->geomMyMeasurementConfigChanged(this->id);
}

/*!
 * \brief Geometry::writeGeometryAttributes
 * \param stream
 * \return
 */
bool Geometry::writeGeometryAttributes(QXmlStreamWriter &stream){

    //this->mConfig.toOpenIndyXML(stream);

    //references to all observations which belong to this geometry
    stream.writeStartElement("observations");
    foreach (Observation *obs, myObservations) {
        obs->writeProxyObservations(stream);
    }
    stream.writeEndElement();

    //references to nominal geometries which belong to this geometry
    stream.writeStartElement("nominalGeometries");
    foreach (Geometry *geom, this->nominals) {
        stream.writeStartElement("geometry");
        stream.writeAttribute("ref", QString::number(geom->id));
        stream.writeEndElement();
    }
    stream.writeEndElement();

    //reference to the nominal coordinate system which this geometry belongs to
    if(this->myNominalCoordSys != NULL){
        stream.writeStartElement("coordinatesystem");
        stream.writeAttribute("ref", QString::number(this->myNominalCoordSys->getId()));
        stream.writeEndElement();
    }

    //reference to measurement config with which this geometry was measured the last time
    if(!this->isNominal){
        stream.writeStartElement("measurementconfig");
        stream.writeAttribute("name", this->mConfig.name);
        //TODO this->mConfig.writeMeasurementConfig(stream);
        stream.writeEndElement();
    }

    //write attributes that every feature contains
    this->writeFeatureAttributes(stream);

    return true;
}

/*!
 * \brief Geometry::readGeometryAttributes
 * \param xml
 * \param dependencies
 * \return
 */
bool Geometry::readGeometryAttributes(QXmlStreamReader &xml, ElementDependencies &dependencies){

    if(xml.name() == "standardDeviation") {

        if(xml.tokenType() == QXmlStreamReader::StartElement) {
            QXmlStreamAttributes sigmaAttributes = xml.attributes();
            if(sigmaAttributes.hasAttribute("value")){
               this->myStatistic.stdev = sigmaAttributes.value("value").toDouble();
            }
         }
        xml.readNext();
    }else if(xml.name() == "measurementconfig") {

        while(!(xml.tokenType() == QXmlStreamReader::EndElement &&
                xml.name() == "measurementconfig")) {
            if(xml.tokenType() == QXmlStreamReader::StartElement) {

                QXmlStreamAttributes measurementconfigAttributes = xml.attributes();

                if(!this->isNominal){

                    if(measurementconfigAttributes.hasAttribute("name")){
                      //TODO MeasurementConfig setzten
                    }

                 }
             }
            xml.readNext();
        }
    }else if(xml.name().compare("observations") == 0){

        xml.readNext();
        while( !xml.atEnd() && xml.name().compare("observations") != 0 ){
            if(xml.tokenType() == QXmlStreamReader::StartElement){
                if(xml.attributes().hasAttribute("ref")){
                    dependencies.addObservationID(xml.attributes().value("ref").toInt());
                }
            }
            xml.readNext();
        }

    }else if(xml.name().compare("nominalGeometries") == 0){

        xml.readNext();
        while( !xml.atEnd() && xml.name().compare("nominalGeometries") != 0 ){
            if(xml.tokenType() == QXmlStreamReader::StartElement){
                if(xml.attributes().hasAttribute("ref")){
                    dependencies.addFeatureID(xml.attributes().value("ref").toInt(), "nominalGeometry");
                }
            }
            xml.readNext();
        }

    }else if(xml.name().compare("coordinatesystem") == 0){

        if(xml.attributes().hasAttribute("ref")){
            dependencies.addFeatureID(xml.attributes().value("ref").toInt(),"coordinatesystem");
        }
        xml.readNext();

    }else if(xml.name() == "function"){

        this->readFunction(xml, dependencies);
        xml.readNext();

    }else{

        this->readFeatureAttributes(xml, dependencies);

    }

    return true;


    /*if(xml.name() == "member"){

        while(!(xml.tokenType() == QXmlStreamReader::EndElement &&
                xml.name() == "member")) {
            if(xml.tokenType() == QXmlStreamReader::StartElement) {


                QXmlStreamAttributes memberAttributes = xml.attributes();

                if(memberAttributes.hasAttribute("type")){

                    if (memberAttributes.value("type") == "observation"){

                        if(memberAttributes.hasAttribute("ref")){
                            dependencies.addObservationID(memberAttributes.value("ref").toInt());
                        }

                    }else if (memberAttributes.value("type") == "coordinatesystem"){

                        if(memberAttributes.hasAttribute("ref")){
                            dependencies.addFeatureID(memberAttributes.value("ref").toInt(),"coordinatesystem");
                        }
                    }else if (memberAttributes.value("type") == "nominalGeometry"){

                        if(memberAttributes.hasAttribute("ref")){
                            dependencies.addFeatureID(memberAttributes.value("ref").toInt(),"nominalGeometry");
                        }
                    }else{
                        this->readFeatureAttributes(xml,dependencies);
                    }

                }

            }

            xml.readNext();
        }
    }

    if(xml.name() == "function"){

       this->readFunction(xml, dependencies);

    }

    return true;*/
}

OiVec Geometry::getXYZ() const{
    return OiVec();
}

OiVec Geometry::getIJK() const{
    return OiVec();
}

double Geometry::getRadius() const
{
    return 0.0;
}

double Geometry::getScalar() const
{
    return 0.0;
}

/*!
 * \brief Geometry::getUsedReadingTypes
 * \return
 */
QMap<Configuration::ReadingTypes, QString> Geometry::getUsedReadingTypes() const{
    return this->usedReadingTypes;
}

/*!
 * \brief Geometry::getStatistic
 * \return
 */
Statistic Geometry::getStatistic() const{
    return this->myStatistic;
}

/*!
 * \brief Geometry::setStatistic
 * \param myStatistic
 */
void Geometry::setStatistic(Statistic myStatistic){
    this->myStatistic = myStatistic;
    emit this->geomMyStatisticChanged(this->id);
}

SimulationData& Geometry::getSimulationData()
{
    return this->mySimulationData;
}

void Geometry::setSimulationData(SimulationData s)
{
    this->mySimulationData = s;
}

/*!
 * \brief Geometry::toOpenIndyXML
 * \param xmlDoc
 * \return
 */
QDomElement Geometry::toOpenIndyXML(QDomDocument &xmlDoc) const{

    QDomElement geometry = Feature::toOpenIndyXML(xmlDoc);

    if(geometry.isNull()){
        return geometry;
    }

    geometry.setTagName("geometry");

    //set geometry attributes
    geometry.setAttribute("nominal", this->getIsNominal());
    geometry.setAttribute("common", this->getIsCommon());

    //add coordinates
    QDomElement coordinates = xmlDoc.createElement("coordinates");
    OiVec xyz = this->getXYZ();
    if(xyz.getSize() >= 3 && (this->getIsSolved() || this->getIsNominal())){
        coordinates.setAttribute("x", xyz.getAt(0));
        coordinates.setAttribute("y", xyz.getAt(1));
        coordinates.setAttribute("z", xyz.getAt(2));
    }else{
        coordinates.setAttribute("x", 0.0);
        coordinates.setAttribute("y", 0.0);
        coordinates.setAttribute("z", 0.0);
    }
    geometry.appendChild(coordinates);

    //add standard deviation
    QDomElement stdv = xmlDoc.createElement("standardDeviation");
    if(this->getIsSolved()){
        stdv.setAttribute("value", this->myStatistic.stdev);
    }else{
        stdv.setAttribute("value", 0.0);
    }
    geometry.appendChild(stdv);

    //add observations
    if(!this->getIsNominal() && this->myObservations.size() > 0){
        QDomElement observations = xmlDoc.createElement("observations");
        foreach(Observation *obs, this->myObservations){
            QDomElement observation = xmlDoc.createElement("observation");
            observation.setAttribute("ref", obs->getId());
            observations.appendChild(observation);
        }
        geometry.appendChild(observations);
    }

    //add nominal system
    if(this->getIsNominal() && this->myNominalCoordSys != NULL){
        QDomElement nominalSystem = xmlDoc.createElement("nominalCoordinateSystem");
        nominalSystem.setAttribute("ref", this->myNominalCoordSys->getId());
        geometry.appendChild(nominalSystem);
    }

    //add corresponding actual geometry
    if(this->getIsNominal() && this->myActual != NULL){
        QDomElement actual = xmlDoc.createElement("actual");
        actual.setAttribute("ref", this->myActual->getId());
        geometry.appendChild(actual);
    }

    //add nominals
    if(!this->getIsNominal() && this->nominals.size() >= 0){
        QDomElement nominals = xmlDoc.createElement("nominalGeometries");
        foreach(Geometry *geom, this->nominals){
            if(geom != NULL){
                QDomElement nominal = xmlDoc.createElement("geometry");
                nominal.setAttribute("ref", geom->getId());
                nominals.appendChild(nominal);
            }
        }
        geometry.appendChild(nominals);
    }

    //add measurement config
    if(!this->getIsNominal()){
        QDomElement mConfig = xmlDoc.createElement("measurementConfig");
        mConfig.setAttribute("name", this->mConfig.name);
        geometry.appendChild(mConfig);
    }

    return geometry;

}

/*!
 * \brief Geometry::fromOpenIndyXML
 * \param xmlDoc
 * \return
 */
bool Geometry::fromOpenIndyXML(QDomElement &xmlElem){

    bool result = Feature::fromOpenIndyXML(xmlElem);

    if(result){

        //set geometry attributes
        if(!xmlElem.hasAttribute("nominal") || !xmlElem.hasAttribute("common")){
            return false;
        }
        this->isNominal = xmlElem.attribute("nominal").toInt();
        this->isCommon = xmlElem.attribute("common").toInt();

        //set standard deviation
        QDomElement stdv = xmlElem.firstChildElement("standardDeviation");
        if(stdv.isNull() || !stdv.hasAttribute("value")){
            return false;
        }
        this->myStatistic.stdev = stdv.attribute("value").toDouble();

    }

    return result;

}

void Geometry::resetSimulationData()
{
    SimulationData d;
    this->mySimulationData = d;

}
