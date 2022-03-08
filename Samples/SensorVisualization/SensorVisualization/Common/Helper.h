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



		inline void SetupDataFolder() {
			String^ const dataFolder = ApplicationData::Current->LocalFolder->Path + "\\Data";

			std::wstring const dataFolderW(dataFolder->Begin());
			std::string const dataFolderA(dataFolderW.begin(), dataFolderW.end());

			if (std::filesystem::exists(dataFolderA)) {
				std::filesystem::remove_all(dataFolderA);
			}

			ApplicationData::Current->LocalFolder->CreateFolderAsync("Data", CreationCollisionOption::FailIfExists);
		}
	}
}


