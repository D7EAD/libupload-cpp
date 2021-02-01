<h1 align="center">libupload-cpp</h1></center>
<p align="center">A C++20 library to upload files--easily.</p>
<hr>
libupload-cpp is a C++20 library that allows users to seamlessly upload files to remote upload sites within their programs without having to deal with all the HTTP(S) nonsense.
<br><br>

<h1>Dependencies</h1>
<ul>
  <li>cURL: for CPR.</li>
  <li>CPR: used as a cURL wrapper to make requests easier.</li>
  <li>OpenSSL: for SSL/TLS requests.</li>
  <li>nlohmann-json: for parsing and extracting JSON values from requests.</li>
</ul>
<i>Dependencies used for developing libupload-cpp were integrated via vcpkg.</i>

<br><br>
As of now, there are only three APIs in libupload-cpp--AnonFile, BayFiles, and File.io. Their identifiers can be found below:

```
enum api_identifiers {
  API_ANONFILE = 0x0
  API_BAYFILES = 0x1
  API_FILE_IO = 0x2
};
```

<br><br>
Files can be uploaded very easily within programs. You can find an example below:

```
#include "libupload.h"
...
int main() {
  try {
    libupload lib(path_to_file);
    libupload::response res = lib.sendfile(API_ANONFILE);
    std::cout << res.URL;
  }
  catch (luException &e) {
    std::cout << e.what();
  }
}
```

<br>

```
Output:
  https://anonfiles.com/NaV9dwaCap9
```
