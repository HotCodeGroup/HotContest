#ifndef REGISTER_H
#define REGISTER_H

#include <QObject>

class Register : public QObject
{
    Q_OBJECT
public:
    explicit Register(QObject *parent = nullptr);

private:
    void registerTypes() const;
};

#endif // REGISTER_H
