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



		inline std::tuple<std::string, std::string, std::string> SetupDataFolders() {
			Platform::String^ accFolder = ApplicationData::Current->LocalFolder->Path + "\\Accelerometer";
			Platform::String^ gyroFolder = ApplicationData::Current->LocalFolder->Path + "\\Gyroscope";
			Platform::String^ magFolder = ApplicationData::Current->LocalFolder->Path + "\\Magnetometer";
			std::wstring accFolderW(accFolder->Begin());
			std::wstring gyroFolderW(gyroFolder->Begin());
			std::wstring magFolderW(magFolder->Begin());
			std::string accFolderA(accFolderW.begin(), accFolderW.end());
			std::string gyroFolderA(gyroFolderW.begin(), gyroFolderW.end());
			std::string magFolderA(magFolderW.begin(), magFolderW.end());
			if (std::filesystem::exists(accFolderA)) {
				std::filesystem::remove_all(accFolderA);
			}
			if (std::filesystem::exists(gyroFolderA)) {
				std::filesystem::remove_all(gyroFolderA);
			}
			if (std::filesystem::exists(magFolderA)) {
				std::filesystem::remove_all(magFolderA);
			}

			ApplicationData::Current->LocalFolder->CreateFolderAsync("Accelerometer", CreationCollisionOption::FailIfExists);
			ApplicationData::Current->LocalFolder->CreateFolderAsync("Gyroscope", CreationCollisionOption::FailIfExists);
			ApplicationData::Current->LocalFolder->CreateFolderAsync("Magnetometer", CreationCollisionOption::FailIfExists);
			std::string accFolderString = (std::string)accFolderA.c_str();
			std::string gyroFolderString = (std::string)gyroFolderA.c_str();
			std::string magFolderString = (std::string)magFolderA.c_str();

			return {accFolderString, gyroFolderString, magFolderString};
		}
	}
}


