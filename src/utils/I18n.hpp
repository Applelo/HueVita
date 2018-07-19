
#ifndef HUEVITA_I18N_HPP
#define HUEVITA_I18N_HPP

#include <string>
#include <map>
#include <jansson.h>
#include <psp2/apputil.h>
#include <psp2/system_param.h>

class I18n {
    private:
        json_t *i18n_file;
        int lang;
    public:
        I18n();
        std::map<std::string, std::string> getI18nByCat(std::string cat);
};


#endif //HUEVITA_I18N_HPP
