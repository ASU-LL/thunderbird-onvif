/* --------------------------------------------------------------------------
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
-----------------------------------------------------------------------------
 serverMedia.cpp
 
 media.wsdl server
----------------------------------------------------------------------------- */

#include "soapMediaBindingService.h"
#include "onvif_impl.h"

int MediaBindingService::GetServiceCapabilities(_trt__GetServiceCapabilities *trt__GetServiceCapabilities, _trt__GetServiceCapabilitiesResponse &trt__GetServiceCapabilitiesResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	ServiceContext* ctx = (ServiceContext*)this->soap->user;	
	trt__GetServiceCapabilitiesResponse.Capabilities = ctx->getMediaServiceCapabilities(this->soap);	
	return SOAP_OK;
}

int MediaBindingService::GetVideoSources(_trt__GetVideoSources *trt__GetVideoSources, _trt__GetVideoSourcesResponse &trt__GetVideoSourcesResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	ServiceContext* ctx = (ServiceContext*)this->soap->user;
	
	int width;
	int height;
	int format;
	// TODO: implement this
	for (auto it: ctx->m_devices) 
	{
		if (ctx->getFormat(it.first.c_str(), width, height, format))
		{
			trt__GetVideoSourcesResponse.VideoSources.push_back(soap_new_tt__VideoSource(this->soap));
			trt__GetVideoSourcesResponse.VideoSources.back()->token = it.first;
			trt__GetVideoSourcesResponse.VideoSources.back()->Resolution = soap_new_req_tt__VideoResolution(this->soap, width, height);
			trt__GetVideoSourcesResponse.VideoSources.back()->Imaging = soap_new_tt__ImagingSettings(this->soap);		
		}
	}
	
	return SOAP_OK;
}

int MediaBindingService::GetAudioSources(_trt__GetAudioSources *trt__GetAudioSources, _trt__GetAudioSourcesResponse &trt__GetAudioSourcesResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetAudioOutputs(_trt__GetAudioOutputs *trt__GetAudioOutputs, _trt__GetAudioOutputsResponse &trt__GetAudioOutputsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::CreateProfile(_trt__CreateProfile *trt__CreateProfile, _trt__CreateProfileResponse &trt__CreateProfileResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetProfile(_trt__GetProfile *trt__GetProfile, _trt__GetProfileResponse &trt__GetProfileResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	ServiceContext* ctx = (ServiceContext*)this->soap->user;
	int ret = SOAP_FAULT;
	
	std::cout << __FUNCTION__ << " search for profile:" << trt__GetProfile->ProfileToken << std::endl;

	auto it = ctx->m_devices.find(trt__GetProfile->ProfileToken);
	if (it != ctx->m_devices.end())
	{
		trt__GetProfileResponse.Profile = ctx->getProfile(this->soap, it->first);
		ret = SOAP_OK;
	}
	
	return ret;
}

int MediaBindingService::GetProfiles(_trt__GetProfiles *trt__GetProfiles, _trt__GetProfilesResponse &trt__GetProfilesResponse) 
{
	std::cout << __FUNCTION__ << std::endl;	
	ServiceContext* ctx = (ServiceContext*)this->soap->user;

	for (auto it: ctx->m_devices) 
	{
		trt__GetProfilesResponse.Profiles.push_back(ctx->getProfile(this->soap, it.first));
	}
	
	return SOAP_OK;
}

int MediaBindingService::AddVideoEncoderConfiguration(_trt__AddVideoEncoderConfiguration *trt__AddVideoEncoderConfiguration, _trt__AddVideoEncoderConfigurationResponse &trt__AddVideoEncoderConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::AddVideoSourceConfiguration(_trt__AddVideoSourceConfiguration *trt__AddVideoSourceConfiguration, _trt__AddVideoSourceConfigurationResponse &trt__AddVideoSourceConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::AddAudioEncoderConfiguration(_trt__AddAudioEncoderConfiguration *trt__AddAudioEncoderConfiguration, _trt__AddAudioEncoderConfigurationResponse &trt__AddAudioEncoderConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::AddAudioSourceConfiguration(_trt__AddAudioSourceConfiguration *trt__AddAudioSourceConfiguration, _trt__AddAudioSourceConfigurationResponse &trt__AddAudioSourceConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::AddPTZConfiguration(_trt__AddPTZConfiguration *trt__AddPTZConfiguration, _trt__AddPTZConfigurationResponse &trt__AddPTZConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::AddVideoAnalyticsConfiguration(_trt__AddVideoAnalyticsConfiguration *trt__AddVideoAnalyticsConfiguration, _trt__AddVideoAnalyticsConfigurationResponse &trt__AddVideoAnalyticsConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::AddMetadataConfiguration(_trt__AddMetadataConfiguration *trt__AddMetadataConfiguration, _trt__AddMetadataConfigurationResponse &trt__AddMetadataConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::AddAudioOutputConfiguration(_trt__AddAudioOutputConfiguration *trt__AddAudioOutputConfiguration, _trt__AddAudioOutputConfigurationResponse &trt__AddAudioOutputConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::AddAudioDecoderConfiguration(_trt__AddAudioDecoderConfiguration *trt__AddAudioDecoderConfiguration, _trt__AddAudioDecoderConfigurationResponse &trt__AddAudioDecoderConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::RemoveVideoEncoderConfiguration(_trt__RemoveVideoEncoderConfiguration *trt__RemoveVideoEncoderConfiguration, _trt__RemoveVideoEncoderConfigurationResponse &trt__RemoveVideoEncoderConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::RemoveVideoSourceConfiguration(_trt__RemoveVideoSourceConfiguration *trt__RemoveVideoSourceConfiguration, _trt__RemoveVideoSourceConfigurationResponse &trt__RemoveVideoSourceConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::RemoveAudioEncoderConfiguration(_trt__RemoveAudioEncoderConfiguration *trt__RemoveAudioEncoderConfiguration, _trt__RemoveAudioEncoderConfigurationResponse &trt__RemoveAudioEncoderConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::RemoveAudioSourceConfiguration(_trt__RemoveAudioSourceConfiguration *trt__RemoveAudioSourceConfiguration, _trt__RemoveAudioSourceConfigurationResponse &trt__RemoveAudioSourceConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::RemovePTZConfiguration(_trt__RemovePTZConfiguration *trt__RemovePTZConfiguration, _trt__RemovePTZConfigurationResponse &trt__RemovePTZConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::RemoveVideoAnalyticsConfiguration(_trt__RemoveVideoAnalyticsConfiguration *trt__RemoveVideoAnalyticsConfiguration, _trt__RemoveVideoAnalyticsConfigurationResponse &trt__RemoveVideoAnalyticsConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::RemoveMetadataConfiguration(_trt__RemoveMetadataConfiguration *trt__RemoveMetadataConfiguration, _trt__RemoveMetadataConfigurationResponse &trt__RemoveMetadataConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::RemoveAudioOutputConfiguration(_trt__RemoveAudioOutputConfiguration *trt__RemoveAudioOutputConfiguration, _trt__RemoveAudioOutputConfigurationResponse &trt__RemoveAudioOutputConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::RemoveAudioDecoderConfiguration(_trt__RemoveAudioDecoderConfiguration *trt__RemoveAudioDecoderConfiguration, _trt__RemoveAudioDecoderConfigurationResponse &trt__RemoveAudioDecoderConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::DeleteProfile(_trt__DeleteProfile *trt__DeleteProfile, _trt__DeleteProfileResponse &trt__DeleteProfileResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetVideoSourceConfigurations(_trt__GetVideoSourceConfigurations *trt__GetVideoSourceConfigurations, _trt__GetVideoSourceConfigurationsResponse &trt__GetVideoSourceConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	ServiceContext* ctx = (ServiceContext*)this->soap->user;
	
	for (auto it: ctx->m_devices) 
	{	
		trt__GetVideoSourceConfigurationsResponse.Configurations.push_back(ctx->getVideoSourceCfg(this->soap, it.first));
	}
	return SOAP_OK;
}

int MediaBindingService::GetVideoEncoderConfigurations(_trt__GetVideoEncoderConfigurations *trt__GetVideoEncoderConfigurations, _trt__GetVideoEncoderConfigurationsResponse &trt__GetVideoEncoderConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	ServiceContext* ctx = (ServiceContext*)this->soap->user;
	
	for (auto it: ctx->m_devices) 
	{	
		trt__GetVideoEncoderConfigurationsResponse.Configurations.push_back(ctx->getVideoEncoderCfg(this->soap, it.first));
	}
	
	return SOAP_OK;
}

int MediaBindingService::GetAudioSourceConfigurations(_trt__GetAudioSourceConfigurations *trt__GetAudioSourceConfigurations, _trt__GetAudioSourceConfigurationsResponse &trt__GetAudioSourceConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetAudioEncoderConfigurations(_trt__GetAudioEncoderConfigurations *trt__GetAudioEncoderConfigurations, _trt__GetAudioEncoderConfigurationsResponse &trt__GetAudioEncoderConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetVideoAnalyticsConfigurations(_trt__GetVideoAnalyticsConfigurations *trt__GetVideoAnalyticsConfigurations, _trt__GetVideoAnalyticsConfigurationsResponse &trt__GetVideoAnalyticsConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetMetadataConfigurations(_trt__GetMetadataConfigurations *trt__GetMetadataConfigurations, _trt__GetMetadataConfigurationsResponse &trt__GetMetadataConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetAudioOutputConfigurations(_trt__GetAudioOutputConfigurations *trt__GetAudioOutputConfigurations, _trt__GetAudioOutputConfigurationsResponse &trt__GetAudioOutputConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetAudioDecoderConfigurations(_trt__GetAudioDecoderConfigurations *trt__GetAudioDecoderConfigurations, _trt__GetAudioDecoderConfigurationsResponse &trt__GetAudioDecoderConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetVideoSourceConfiguration(_trt__GetVideoSourceConfiguration *trt__GetVideoSourceConfiguration, _trt__GetVideoSourceConfigurationResponse &trt__GetVideoSourceConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	ServiceContext* ctx = (ServiceContext*)this->soap->user;
	
	auto it = ctx->m_devices.find(trt__GetVideoSourceConfiguration->ConfigurationToken);
	if (it != ctx->m_devices.end())
	{
		trt__GetVideoSourceConfigurationResponse.Configuration = ctx->getVideoSourceCfg(this->soap, it->first);
	}
	
	return SOAP_OK;
}

int MediaBindingService::GetVideoEncoderConfiguration(_trt__GetVideoEncoderConfiguration *trt__GetVideoEncoderConfiguration, _trt__GetVideoEncoderConfigurationResponse &trt__GetVideoEncoderConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	ServiceContext* ctx = (ServiceContext*)this->soap->user;

	auto it = ctx->m_devices.find(trt__GetVideoEncoderConfiguration->ConfigurationToken);
	if (it != ctx->m_devices.end())
	{
		trt__GetVideoEncoderConfigurationResponse.Configuration = ctx->getVideoEncoderCfg(this->soap, it->first);	
	}
	
	return SOAP_OK;
}

int MediaBindingService::GetAudioSourceConfiguration(_trt__GetAudioSourceConfiguration *trt__GetAudioSourceConfiguration, _trt__GetAudioSourceConfigurationResponse &trt__GetAudioSourceConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetAudioEncoderConfiguration(_trt__GetAudioEncoderConfiguration *trt__GetAudioEncoderConfiguration, _trt__GetAudioEncoderConfigurationResponse &trt__GetAudioEncoderConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetVideoAnalyticsConfiguration(_trt__GetVideoAnalyticsConfiguration *trt__GetVideoAnalyticsConfiguration, _trt__GetVideoAnalyticsConfigurationResponse &trt__GetVideoAnalyticsConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetMetadataConfiguration(_trt__GetMetadataConfiguration *trt__GetMetadataConfiguration, _trt__GetMetadataConfigurationResponse &trt__GetMetadataConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetAudioOutputConfiguration(_trt__GetAudioOutputConfiguration *trt__GetAudioOutputConfiguration, _trt__GetAudioOutputConfigurationResponse &trt__GetAudioOutputConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetAudioDecoderConfiguration(_trt__GetAudioDecoderConfiguration *trt__GetAudioDecoderConfiguration, _trt__GetAudioDecoderConfigurationResponse &trt__GetAudioDecoderConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetCompatibleVideoEncoderConfigurations(_trt__GetCompatibleVideoEncoderConfigurations *trt__GetCompatibleVideoEncoderConfigurations, _trt__GetCompatibleVideoEncoderConfigurationsResponse &trt__GetCompatibleVideoEncoderConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	ServiceContext* ctx = (ServiceContext*)this->soap->user;

	auto it = ctx->m_devices.find(trt__GetCompatibleVideoEncoderConfigurations->ProfileToken);
	if (it != ctx->m_devices.end())
	{
		trt__GetCompatibleVideoEncoderConfigurationsResponse.Configurations.push_back(ctx->getVideoEncoderCfg(this->soap, it->first));
	}
	
	return SOAP_OK;
}

int MediaBindingService::GetCompatibleVideoSourceConfigurations(_trt__GetCompatibleVideoSourceConfigurations *trt__GetCompatibleVideoSourceConfigurations, _trt__GetCompatibleVideoSourceConfigurationsResponse &trt__GetCompatibleVideoSourceConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	ServiceContext* ctx = (ServiceContext*)this->soap->user;

	auto it = ctx->m_devices.find(trt__GetCompatibleVideoSourceConfigurations->ProfileToken);
	if (it != ctx->m_devices.end())
	{
		trt__GetCompatibleVideoSourceConfigurationsResponse.Configurations.push_back(ctx->getVideoSourceCfg(this->soap, it->first));
	}
	return SOAP_OK;
}

int MediaBindingService::GetCompatibleAudioEncoderConfigurations(_trt__GetCompatibleAudioEncoderConfigurations *trt__GetCompatibleAudioEncoderConfigurations, _trt__GetCompatibleAudioEncoderConfigurationsResponse &trt__GetCompatibleAudioEncoderConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetCompatibleAudioSourceConfigurations(_trt__GetCompatibleAudioSourceConfigurations *trt__GetCompatibleAudioSourceConfigurations, _trt__GetCompatibleAudioSourceConfigurationsResponse &trt__GetCompatibleAudioSourceConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetCompatibleVideoAnalyticsConfigurations(_trt__GetCompatibleVideoAnalyticsConfigurations *trt__GetCompatibleVideoAnalyticsConfigurations, _trt__GetCompatibleVideoAnalyticsConfigurationsResponse &trt__GetCompatibleVideoAnalyticsConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetCompatibleMetadataConfigurations(_trt__GetCompatibleMetadataConfigurations *trt__GetCompatibleMetadataConfigurations, _trt__GetCompatibleMetadataConfigurationsResponse &trt__GetCompatibleMetadataConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetCompatibleAudioOutputConfigurations(_trt__GetCompatibleAudioOutputConfigurations *trt__GetCompatibleAudioOutputConfigurations, _trt__GetCompatibleAudioOutputConfigurationsResponse &trt__GetCompatibleAudioOutputConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetCompatibleAudioDecoderConfigurations(_trt__GetCompatibleAudioDecoderConfigurations *trt__GetCompatibleAudioDecoderConfigurations, _trt__GetCompatibleAudioDecoderConfigurationsResponse &trt__GetCompatibleAudioDecoderConfigurationsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::SetVideoSourceConfiguration(_trt__SetVideoSourceConfiguration *trt__SetVideoSourceConfiguration, _trt__SetVideoSourceConfigurationResponse &trt__SetVideoSourceConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::SetVideoEncoderConfiguration(_trt__SetVideoEncoderConfiguration *trt__SetVideoEncoderConfiguration, _trt__SetVideoEncoderConfigurationResponse &trt__SetVideoEncoderConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::SetAudioSourceConfiguration(_trt__SetAudioSourceConfiguration *trt__SetAudioSourceConfiguration, _trt__SetAudioSourceConfigurationResponse &trt__SetAudioSourceConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::SetAudioEncoderConfiguration(_trt__SetAudioEncoderConfiguration *trt__SetAudioEncoderConfiguration, _trt__SetAudioEncoderConfigurationResponse &trt__SetAudioEncoderConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::SetVideoAnalyticsConfiguration(_trt__SetVideoAnalyticsConfiguration *trt__SetVideoAnalyticsConfiguration, _trt__SetVideoAnalyticsConfigurationResponse &trt__SetVideoAnalyticsConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::SetMetadataConfiguration(_trt__SetMetadataConfiguration *trt__SetMetadataConfiguration, _trt__SetMetadataConfigurationResponse &trt__SetMetadataConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::SetAudioOutputConfiguration(_trt__SetAudioOutputConfiguration *trt__SetAudioOutputConfiguration, _trt__SetAudioOutputConfigurationResponse &trt__SetAudioOutputConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::SetAudioDecoderConfiguration(_trt__SetAudioDecoderConfiguration *trt__SetAudioDecoderConfiguration, _trt__SetAudioDecoderConfigurationResponse &trt__SetAudioDecoderConfigurationResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetVideoSourceConfigurationOptions(_trt__GetVideoSourceConfigurationOptions *trt__GetVideoSourceConfigurationOptions, _trt__GetVideoSourceConfigurationOptionsResponse &trt__GetVideoSourceConfigurationOptionsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	ServiceContext* ctx = (ServiceContext*)this->soap->user;
	
	if (trt__GetVideoSourceConfigurationOptions->ConfigurationToken)
	{
		auto it = ctx->m_devices.find(trt__GetVideoSourceConfigurationOptions->ConfigurationToken->c_str());
		if (it != ctx->m_devices.end())
		{	
			trt__GetVideoSourceConfigurationOptionsResponse.Options = ctx->getVideoSourceCfgOptions(soap, it->first);
		}
	}
	return SOAP_OK;
}

int MediaBindingService::GetVideoEncoderConfigurationOptions(_trt__GetVideoEncoderConfigurationOptions *trt__GetVideoEncoderConfigurationOptions, _trt__GetVideoEncoderConfigurationOptionsResponse &trt__GetVideoEncoderConfigurationOptionsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;	
	ServiceContext* ctx = (ServiceContext*)this->soap->user;
	
	if (trt__GetVideoEncoderConfigurationOptions->ConfigurationToken)
	{
		auto it = ctx->m_devices.find(trt__GetVideoEncoderConfigurationOptions->ConfigurationToken->c_str());
		if (it != ctx->m_devices.end())
		{	
			trt__GetVideoEncoderConfigurationOptionsResponse.Options = ctx->getVideoEncoderCfgOptions(soap, it->first);
		}
	}
	
	return SOAP_OK;
}

int MediaBindingService::GetAudioSourceConfigurationOptions(_trt__GetAudioSourceConfigurationOptions *trt__GetAudioSourceConfigurationOptions, _trt__GetAudioSourceConfigurationOptionsResponse &trt__GetAudioSourceConfigurationOptionsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetAudioEncoderConfigurationOptions(_trt__GetAudioEncoderConfigurationOptions *trt__GetAudioEncoderConfigurationOptions, _trt__GetAudioEncoderConfigurationOptionsResponse &trt__GetAudioEncoderConfigurationOptionsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetMetadataConfigurationOptions(_trt__GetMetadataConfigurationOptions *trt__GetMetadataConfigurationOptions, _trt__GetMetadataConfigurationOptionsResponse &trt__GetMetadataConfigurationOptionsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;

	ServiceContext* ctx = (ServiceContext*)this->soap->user;
	
	if (trt__GetMetadataConfigurationOptions->ConfigurationToken)
	{
		auto it = ctx->m_devices.find(trt__GetMetadataConfigurationOptions->ConfigurationToken->c_str());
		if (it != ctx->m_devices.end())
		{	
			trt__GetMetadataConfigurationOptionsResponse.Options = ctx->getMetadataCfgOptions(soap, it->first);
		}
	}

	return SOAP_OK;
}

int MediaBindingService::GetAudioOutputConfigurationOptions(_trt__GetAudioOutputConfigurationOptions *trt__GetAudioOutputConfigurationOptions, _trt__GetAudioOutputConfigurationOptionsResponse &trt__GetAudioOutputConfigurationOptionsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetAudioDecoderConfigurationOptions(_trt__GetAudioDecoderConfigurationOptions *trt__GetAudioDecoderConfigurationOptions, _trt__GetAudioDecoderConfigurationOptionsResponse &trt__GetAudioDecoderConfigurationOptionsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetGuaranteedNumberOfVideoEncoderInstances(_trt__GetGuaranteedNumberOfVideoEncoderInstances *trt__GetGuaranteedNumberOfVideoEncoderInstances, _trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse &trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetStreamUri(_trt__GetStreamUri *trt__GetStreamUri, _trt__GetStreamUriResponse &trt__GetStreamUriResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	ServiceContext* ctx = (ServiceContext*)this->soap->user;
	int ret = SOAP_FAULT;
	
	trt__GetStreamUriResponse.MediaUri = soap_new_tt__MediaUri(this->soap);
	if (trt__GetStreamUri != NULL)
	{
		std::cout << __FUNCTION__ << " search for profile:" << trt__GetStreamUri->ProfileToken << std::endl;
		auto it = ctx->m_devices.find(trt__GetStreamUri->ProfileToken);
		if (it != ctx->m_devices.end())
		{
			trt__GetStreamUriResponse.MediaUri->Uri.assign(it->second.m_rtsp_url);
			ret = SOAP_OK;
		}
	}	
	return ret;
}

int MediaBindingService::StartMulticastStreaming(_trt__StartMulticastStreaming *trt__StartMulticastStreaming, _trt__StartMulticastStreamingResponse &trt__StartMulticastStreamingResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::StopMulticastStreaming(_trt__StopMulticastStreaming *trt__StopMulticastStreaming, _trt__StopMulticastStreamingResponse &trt__StopMulticastStreamingResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::SetSynchronizationPoint(_trt__SetSynchronizationPoint *trt__SetSynchronizationPoint, _trt__SetSynchronizationPointResponse &trt__SetSynchronizationPointResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetSnapshotUri(_trt__GetSnapshotUri *trt__GetSnapshotUri, _trt__GetSnapshotUriResponse &trt__GetSnapshotUriResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	ServiceContext* ctx = (ServiceContext*)this->soap->user;
	int ret = SOAP_FAULT;
	
	trt__GetSnapshotUriResponse.MediaUri = soap_new_tt__MediaUri(soap);
	if (trt__GetSnapshotUri != NULL)
	{
		std::cout << __FUNCTION__ << " search for profile:" << trt__GetSnapshotUri->ProfileToken << std::endl;
		auto it = ctx->m_devices.find(trt__GetSnapshotUri->ProfileToken);
		if (it != ctx->m_devices.end())
		{
			trt__GetSnapshotUriResponse.MediaUri->Uri.assign(it->second.m_rtsp_url);
			ret = SOAP_OK;
		}
	}	
	return ret;
}

int MediaBindingService::GetVideoSourceModes(_trt__GetVideoSourceModes *trt__GetVideoSourceModes, _trt__GetVideoSourceModesResponse &trt__GetVideoSourceModesResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::SetVideoSourceMode(_trt__SetVideoSourceMode *trt__SetVideoSourceMode, _trt__SetVideoSourceModeResponse &trt__SetVideoSourceModeResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetOSDs(_trt__GetOSDs *trt__GetOSDs, _trt__GetOSDsResponse &trt__GetOSDsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetOSD(_trt__GetOSD *trt__GetOSD, _trt__GetOSDResponse &trt__GetOSDResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::GetOSDOptions(_trt__GetOSDOptions *trt__GetOSDOptions, _trt__GetOSDOptionsResponse &trt__GetOSDOptionsResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::SetOSD(_trt__SetOSD *trt__SetOSD, _trt__SetOSDResponse &trt__SetOSDResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::CreateOSD(_trt__CreateOSD *trt__CreateOSD, _trt__CreateOSDResponse &trt__CreateOSDResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

int MediaBindingService::DeleteOSD(_trt__DeleteOSD *trt__DeleteOSD, _trt__DeleteOSDResponse &trt__DeleteOSDResponse) 
{
	std::cout << __FUNCTION__ << std::endl;
	return SOAP_OK;
}

