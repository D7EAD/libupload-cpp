#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING // kek

#include <iostream>
#include <filesystem>
#include <exception>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>

class luException : public std::exception {
	public:
		luException(const std::string& msg) : m_msg(msg) {}

		virtual const char* what() const {
			return this->m_msg.c_str();
		}
	private:
		const std::string m_msg;
};

enum api_identifiers {
	API_ANONFILE = 0x1,
	API_BAYFILES = 0x2,
	API_FILE_IO = 0x3
};

class libupload {
	public:
		__declspec(dllexport) libupload(std::string filePath);
		typedef struct response {
			std::string URL;
			std::string full_response;
			bool status;
		} *presponse;
		response __declspec(dllexport) sendFile(api_identifiers api);
	private:
		std::string filePath;
		nlohmann::json object;
		typedef struct codeStruct {
			std::string URL;
			unsigned short code;
		};
		codeStruct parseAPI(api_identifiers api);
		void parseCode(unsigned short code, presponse responseStruct, std::string str);
};