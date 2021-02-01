<h1 align="center">libupload-cpp</h1></center>
<p align="center">A C++ library to upload files--easily.</p>
<hr>
libupload-cpp is a C++ library that allows users to seamlessly upload files to remote upload sites within their programs without having to deal with all the HTTP(S) nonsense.
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
    libuplaod lib(path_to_file);
    libupload::response = lib.sendfile(API_ANONFILE);
    std::cout << response.URL;
  }
  catch (luException &e) {
    std::cout << e.what();
  }
}
```

<br><br>

```
Output:
  https://anonfiles.com/NaV9dwaCap9
```
