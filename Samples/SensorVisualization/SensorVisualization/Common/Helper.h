#pragma once

#include <vector>
#include <string>
#include <ostream>
#include <filesystem>
#include <tuple>

#include <debugapi.h>

namespace BasicHologram {
	namespace Helper
	{
		using namespace Windows::Storage;
		using namespace Platform;

		template <typename T>
		void LogMessage(const T value)
		{
			std::ostringstream os;
			os << value << "\n";
			OutputDebugStringA(os.str().c_str());
		}

		template <typename T>
		void LogMessage(const std::vector<T> values, int const format = 1)
		{
			std::ostringstream os;

			for (int i = 0; i < values.size(); i++)
			{
				if (i % format == 0 and i > 0)
				{
					os << "\n";
				}
				os << values[i] << " ";
			}

			OutputDebugStringA(os.str().c_str());
		}



		inline /*std::tuple<std::string, std::string, std::string>*/ void SetupDataFolders() {
			//String^ accFolder = ApplicationData::Current->LocalFolder->Path + "\\Accelerometer";
			//String^ gyroFolder = ApplicationData::Current->LocalFolder->Path + "\\Gyroscope";
			//String^ magFolder = ApplicationData::Current->LocalFolder->Path + "\\Magnetometer";
			//String^ dataFolder = ApplicationData::Current->LocalFolder->Path + "\\Data";

			//std::wstring accFolderW(accFolder->Begin());
			//std::wstring gyroFolderW(gyroFolder->Begin());
			//std::wstring magFolderW(magFolder->Begin());
			//std::wstring dataFolderW(dataFolder->Begin());
			//std::string accFolderA(accFolderW.begin(), accFolderW.end());
			//std::string gyroFolderA(gyroFolderW.begin(), gyroFolderW.end());
			//std::string magFolderA(magFolderW.begin(), magFolderW.end());
			//std::string dataFolderA(dataFolderW.begin(), dataFolderW.end());
			/*if (std::filesystem::exists(accFolderA)) {
				std::filesystem::remove_all(accFolderA);
			}
			if (std::filesystem::exists(gyroFolderA)) {
				std::filesystem::remove_all(gyroFolderA);
			}
			if (std::filesystem::exists(magFolderA)) {
				std::filesystem::remove_all(magFolderA);
			}*//*
			if (std::filesystem::exists(dataFolderA)) {*/
				//std::filesystem::remove_all(dataFolderA);
			//}

			//ApplicationData::Current->LocalFolder->CreateFolderAsync("Accelerometer", CreationCollisionOption::FailIfExists);
			//ApplicationData::Current->LocalFolder->CreateFolderAsync("Gyroscope", CreationCollisionOption::FailIfExists);
			//ApplicationData::Current->LocalFolder->CreateFolderAsync("Magnetometer", CreationCollisionOption::FailIfExists);
			//ApplicationData::Current->LocalFolder->CreateFolderAsync("Data", CreationCollisionOption::FailIfExists);
			//std::string accFolderString = (std::string)accFolderA.c_str();
			//std::string gyroFolderString = (std::string)gyroFolderA.c_str();
			//std::string magFolderString = (std::string)magFolderA.c_str();

			//return {accFolderString, gyroFolderString, magFolderString};
		}
	}
}


