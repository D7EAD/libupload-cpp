#include "libupload.h"

libupload::libupload(std::string filePath) {
    if (!std::filesystem::exists(std::filesystem::path(filePath))) {
        throw luException("Supplied file does not exist!");
    }
    this->filePath = filePath;
}

libupload::response libupload::sendFile(api_identifiers api) {
    libupload::codeStruct code; libupload::response responseStruct;
    code = this->parseAPI(api);
    cpr::Response r = cpr::Post(cpr::Url{code.URL}, cpr::Multipart{{"file", cpr::File{this->filePath}}});

    // begin struct occupying
    this->parseCode(code.code, &responseStruct, r.text);

    // return the struct to user with upload information
    return responseStruct;
}

libupload::codeStruct libupload::parseAPI(api_identifiers api) {
    switch (api) {
        case API_ANONFILE: return { "https://api.anonfiles.com/upload", 1 };
        case API_BAYFILES: return { "https://api.bayfiles.com/upload", 2 };
        case API_FILE_IO: return { "https://file.io/", 3 };
        default: throw luException("Invalid API identifier!"); break;
    }
}

void libupload::parseCode(unsigned short code, libupload::presponse responseStruct, std::string str) {
    this->object = nlohmann::json::parse(str);
    responseStruct->full_response = str; // applies to all APIs
    switch (code) {
        case 1: {
            responseStruct->status = this->object["status"];
            responseStruct->URL = this->object["data"]["file"]["url"]["short"];
        } break;
        case 2: {
            responseStruct->status = this->object["status"];
            responseStruct->URL = this->object["data"]["file"]["url"]["short"];
        } break;
        case 3: {
            responseStruct->status = this->object["success"];
            responseStruct->URL = this->object["link"];
        } break;
    }
}