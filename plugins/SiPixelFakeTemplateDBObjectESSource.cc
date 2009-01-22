#include "CalibTracker/SiPixelESProducers/interface/SiPixelFakeTemplateDBObjectESSource.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

SiPixelFakeTemplateDBObjectESSource::SiPixelFakeTemplateDBObjectESSource(const edm::ParameterSet& conf_) : templateCalibrations_(conf_.getParameter<vstring>("siPixelTemplateCalibrations")),
																																																					 version_(conf_.getParameter<double>("Version"))
{
	edm::LogInfo("SiPixelFakeTemplateDBObjectESSource::SiPixelFakeTemplateDBObjectESSource");
	//the following line is needed to tell the framework what
	// data is being produced
	setWhatProduced(this);
	findingRecord<SiPixelTemplateDBObjectRcd>();
}

SiPixelFakeTemplateDBObjectESSource::~SiPixelFakeTemplateDBObjectESSource()
{
}

std::auto_ptr<SiPixelTemplateDBObject> SiPixelFakeTemplateDBObjectESSource::produce(const SiPixelTemplateDBObjectRcd & )
{
	using namespace edm::es;
	SiPixelTemplateDBObject * obj = new SiPixelTemplateDBObject();
	obj->fillDB(templateCalibrations_);
	obj->setVersion(version_);
	
	//std::cout << *obj << std::endl;
	return std::auto_ptr<SiPixelTemplateDBObject>(obj);
}

void SiPixelFakeTemplateDBObjectESSource::setIntervalFor( const edm::eventsetup::EventSetupRecordKey&, 
	const edm::IOVSyncValue& iosv, 
	edm::ValidityInterval& oValidity ) {
  edm::ValidityInterval infinity( iosv.beginOfTime(), iosv.endOfTime() );
  oValidity = infinity;  
}

