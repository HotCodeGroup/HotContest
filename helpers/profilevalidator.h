#ifndef PROFILEVALIDATOR_H
#define PROFILEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT ProfileValidator : public TFormValidator
{
public:
    ProfileValidator();

    bool validate(const QVariantMap &hash);
};

Q_DECLARE_METATYPE(ProfileValidator)

#endif // PROFILEVALIDATOR_H
