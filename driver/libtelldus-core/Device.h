#pragma once

#include "telldus-core.h"
#include <string>
//#include <QMutex>

namespace TelldusCore {

	const int ALL_METHODS =
			TELLSTICK_TURNON |
			TELLSTICK_TURNOFF |
			TELLSTICK_BELL |
			TELLSTICK_DIM;

	class Device
	{
	public:
		Device(int id, const std::string model, const std::string &name);
		virtual ~Device(void);
		
		int switchState( int newState, const std::string &value = "" );
		virtual int methods(int methodsSupported) = 0;
		virtual std::string getProtocol() const = 0;
		virtual bool parameterMatches( const std::string &name, const std::string &value ) const = 0;
		bool setParameter(const std::string &strName, const std::string &strValue);

		std::string getModel() const;
		bool setModel( const std::string & strModel );
		std::string getName() const;
		bool setName( const std::string &newName );
		
		static int methodId( const std::string &methodName );
		
	#ifdef _LINUX
		void setDevice(const std::string &device);
	protected:
		std::string strDevice;
	#endif
	
	protected:
		virtual bool setDeviceParameter(const std::string &strName, const std::string &strValue) = 0;
		virtual int turnOn(void);
		virtual int turnOff(void);
		virtual int bell(void);
		virtual int dim(unsigned char level);
		int send(const std::string &strMessage);
	
	private:
		int deviceId;
		std::string deviceName, model;
	//	static QMutex deviceMutex;
	};

}
