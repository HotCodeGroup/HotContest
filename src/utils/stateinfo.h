#ifndef STATEINFO_H
#define STATEINFO_H

#include <QString>
#include <QObject>

class StateInfo : public QObject {

    Q_OBJECT
    Q_PROPERTY(bool isLoading READ getIsLoading WRITE setIsLoading NOTIFY isLoadingChanged)

public:
    StateInfo( bool isLoading = true);
    ~StateInfo();

    bool getIsLoading() const;
    void setIsLoading(bool isLoading);

signals:
    void isLoadingChanged(bool);

private:
    bool isLoading;
};

#endif // STATEINFO_H
