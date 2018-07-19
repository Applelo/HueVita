
#include "I18n.hpp"

I18n::I18n() {
    json_error_t error;
    sceAppUtilSystemParamGetInt(SCE_SYSTEM_PARAM_ID_LANG, &lang);
    if (lang == SCE_SYSTEM_PARAM_LANG_FRENCH) {
        i18n_file = json_load_file("app0:i18n/fr.json", 0, &error);
    }
    else {
        i18n_file = json_load_file("app0:i18n/en.json", 0, &error);
    }
}

std::map<std::string, std::string> I18n::getI18nByCat(std::string cat) {
    std::map<std::string, std::string> result;

    json_t *obj = json_object_get(i18n_file, cat.c_str());
    const char *key;
    json_t *value;

    json_object_foreach(obj, key, value) {
        result.insert(std::pair<std::string,std::string>(key, json_string_value(value)));
    }

    return result;
}