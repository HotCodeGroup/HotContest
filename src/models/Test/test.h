#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QString>
#include <QDateTime>

class Test : public QObject {

    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(const QString& inputData READ getInputData WRITE setInputData NOTIFY inputDataChanged)
    Q_PROPERTY(const QString& trueOutputData READ getTrueOutputData WRITE setTrueOutputData NOTIFY trueOutputDataChanged)
    Q_PROPERTY(const QString& realOutputData READ getRealOutputData WRITE setRealOutputData NOTIFY realOutputDataChanged)

public:
    Test(int id = 0, const QString& inputData = "",
         const QString& trueOutputData = "", const QString& realOutputData = "");
    ~Test();

    int getId() const;
    void setId(int id);

    const QString& getInputData() const;
    void setInputData(const QString& inputData);

    const QString& getTrueOutputData() const;
    void setTrueOutputData(const QString& trueOutputData);

    const QString& getRealOutputData() const;
    void setRealOutputData(const QString& realOutputData);

signals:
    void idChanged(int);
    void inputDataChanged(const QString&);
    void trueOutputDataChanged(const QString&);
    void realOutputDataChanged(const QString&);

private:
    int id;
    QString inputData;
    QString trueOutputData;
    QString realOutputData;
};

#endif // TEST_H
