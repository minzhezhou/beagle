/*
 *  Request.hpp
 *  Copyright (C) 2003-2004 by Marc Dubreuil
 *  Copyright (C) 2001-2002 by Marc Dubreuil, Jacques Labrie, Helene Torresan and Frederic Jean
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Contact:
 *  Laboratoire de Vision et Systemes Numeriques
 *  Departement de genie electrique et de genie informatique
 *  Universite Laval, Quebec, Canada, G1K 7P4
 *  http://vision.gel.ulaval.ca
 *
 */
#ifndef __REQUEST_DAGS_HH
#define __REQUEST_DAGS_HH

#include <string>

namespace DAGS
{

/*!
*  \class Request dags/Request.hpp "dags/Request.hpp"
*  \brief Request class
*
*  This class is used to help parse the XML code returned by the server
*  and to know what error are returned by the server or the client. This class contains the
*  attributes of a request client<->server.
*  getClientId() returns the id of the client that the server give, getError() returns the
*  error generated by either the client or the server, getRequestType() returns the
*  request type(job(subgroup), group or universe), getAppName() returns the application's name.
*/

class Request
{

public:
	/*! \brief Constructor by default
	*/
	Request()
			: mClientId(-1),
			mError(-1),
			mRequestType(""),
			mAppName(""),
			mGroupId(-1),
			mVersion(""),
			mCompression(0)
	{}

	/*! \brief Get the Client ID
	*/
	int getClientId()
	{
		return mClientId;
	}

	/*! \brief Get the error code
	*/
	int getError()
	{
		return mError;
	}

	/*! \brief Get the request Type
	*
	*  Get the request type that tells the server what the client wants (universe,
	*  group or a group of jobs)
	*/
	std::string getRequestType()
	{
		return mRequestType;
	}

	/*! \brief Get the application's name
	*/
	std::string getAppName()
	{
		return mAppName;
	}

	/*! \brief Get the group's id for a request of a specific group
	*/
	int getGroupId()
	{
		return mGroupId;
	}

	/*! \brief Get the client's version
	*/
	std::string getVersion()
	{
		return mVersion;
	}

	/*! \brief Get the client's compression level.
	*/
	unsigned int getCompressionLevel()
	{
		return mCompression;
	}

	/*! \brief Set the Client ID
	*/
	void setClientId(int inClientId)
	{
		mClientId=inClientId;
	}

	/*! \brief Set the error
	*/
	void setError(int inError)
	{
		mError=inError;
	}

	/*! \brief set the request type
	*/
	void setRequestType(std::string inRequestType)
	{
		mRequestType = std::string(inRequestType.c_str());
	}

	/*! \brief Set the application's name
	*/
	void setAppName(std::string inAppName)
	{
		mAppName = inAppName;
	}

	/*! \brief Set the group's id for a request of a specific group
	*/
	void setGroupId(int inGroupId)
	{
		mGroupId = inGroupId;
	}

	/*! \brief Set the client's version
	*/
	void setVersion(std::string inVersion)
	{
		mVersion = inVersion;
	}

	/*! \brief Get the client's compression level.
	*/
	void setCompressionLevel(unsigned int inCompression)
	{
		mCompression = inCompression;
	}

	/*! \brief Copy constructor
	*/
	Request(const Request& inRequest)
	{
		mClientId         = inRequest.mClientId;
		mError            = inRequest.mError;
		mRequestType      = inRequest.mRequestType;
		mAppName          = inRequest.mAppName;
		mUncompressedSize = inRequest.mUncompressedSize;
		mGroupId          = inRequest.mGroupId;
		mVersion          = inRequest.mVersion;
		mCompression      = inRequest.mCompression;
	}


private:

	/*! \brief Client's ID
	*/
	int mClientId;
	/*! \brief Error code
	*/
	int mError;
	/*! \brief Request type
	*/
	std::string mRequestType;
	/*! \brief Application's name
	*/
	std::string mAppName;

	/*! \brief Uncompressed data size when mCompression != "no".
	*/
	unsigned int mUncompressedSize;

	/*! \brief Group's id if > -1
	*/
	int mGroupId;

	/*! \brief Client's version
	*/
	std::string mVersion;

	/*! \brief Client compression level used.
	*/
	unsigned int mCompression;
};
}

#endif
