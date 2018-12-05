#include "profileeditvalidator.h"
#include "../models/profile.h"

ProfileEditValidator::ProfileEditValidator() : TFormValidator()
{
    setRule("username", Tf::Required, false);
    setRule("email", Tf::Required, false);
    setRule("password", Tf::Required, false);
    setRule("first_name", Tf::Required, false);
    setRule("last_name", Tf::Required, false);
    setRule("created_at", Tf::Required, false);
//    setRule("is_active", Tf::Required, false);

    setRule("email", Tf::EmailAddress, true);
}

bool ProfileEditValidator::validate(const QVariantMap &hash)
{
    bool ret = TFormValidator::validate(hash);  // Validation of static rules
    if (ret && hash.find("email") != hash.end()) {
        auto checkProfile = Profile::getByEmail(hash["email"].toString());
        if (!checkProfile.isNull()) {
            setValidationError("This email is already used!");
            return false;
        }
    }

    return ret;
}