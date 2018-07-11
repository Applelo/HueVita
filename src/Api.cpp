//
// Created by bouba on 10/07/2018.
//

#include "Api.hpp"

//curl
struct curl_string {
    char *ptr;
    size_t len;
};

void init_string(struct curl_string *s) {
    s->len = 0;
    s->ptr = (char*)malloc(s->len+1);
    if (s->ptr == NULL) {
        fprintf(stderr, "malloc() failed\n");
        exit(EXIT_FAILURE);
    }
    s->ptr[0] = '\0';
}
size_t writefunc(void *ptr, size_t size, size_t nmemb, struct curl_string *s)
{
    size_t new_len = s->len + size*nmemb;
    s->ptr = (char*)realloc(s->ptr, new_len+1);
    if (s->ptr == NULL) {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(s->ptr+s->len, ptr, size*nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;

    return size*nmemb;
}

//methods
void Api::createUsername() {
    curl = curl_easy_init();

    if (curl) {
        std::string json = "{\"devicetype\":\"huevita#mypsvita\"}";
        struct curl_string result;
        init_string(&result);

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Accept: application/json");
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, this->getApiAddress());
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);

        curlResult = curl_easy_perform(curl);

        json_t *resultJson;
        json_error_t errorJson;

        resultJson = json_loads(result.ptr, 0, &errorJson);
        this->username = json_string_value(
                json_object_get(
                        json_object_get(
                                json_array_get(resultJson, 0),
                                "success"
                        ),
                        "username"
                )
        );
        curl_easy_cleanup(curl);
    }

}

//getter
const std::string &Api::getUsername() const {
    return username;
}
const std::string &Api::getIpAddress() const {
    return ipAddress;
}

std::string Api::getApiAddress() {
    if (username.empty()) {
        return "http://" + ipAddress + "/api";
    }
    return "http://" + ipAddress + "/api/" + username + "/";
}


//setter
void Api::setUsername(const std::string &username) {
    Api::username = username;
}
void Api::setIpAddress(const std::string &ipAddress) {
    Api::ipAddress = ipAddress;
}

