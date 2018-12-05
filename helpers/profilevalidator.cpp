#include "profilevalidator.h"
#include "../models/profile.h"

ProfileValidator::ProfileValidator() : TFormValidator()
{
    setRule("first_name", Tf::Required, false);
    setRule("last_name", Tf::Required, false);
    setRule("created_at", Tf::Required, false);
//    setRule("is_active", Tf::Required, false);

    setRule("email", Tf::EmailAddress, true);
}

bool ProfileValidator::validate(const QVariantMap &hash)
{
    bool ret = TFormValidator::validate(hash);  // Validation of static rules
    if (ret) {
        auto checkProfile = Profile::getByUsername(hash["username"].toString());
        if (!checkProfile.isNull()) {
            setValidationError("This username is already taken!");
            return false;
        }

        checkProfile = Profile::getByEmail(hash["email"].toString());
        if (!checkProfile.isNull()) {
            setValidationError("This email is already used!");
            return false;
        }
    }

    return ret;
}