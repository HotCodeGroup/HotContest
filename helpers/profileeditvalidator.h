#ifndef PROFILEEDITVALIDATOR_H
#define PROFILEEDITVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT ProfileEditValidator : public TFormValidator
{
public:
    ProfileEditValidator();

    bool validate(const QVariantMap &hash);
};

Q_DECLARE_METATYPE(ProfileEditValidator)

#endif // PROFILEEDITVALIDATOR_H
