#include <TfTest/TfTest>
#include "models/profile.h"    //  include the model class

class TestProfile : public QObject
{
    Q_OBJECT
private slots:
    void create_data();
    void create();
};
static Profile create(const QString &firstName, const QString &lastName, const QString &nickname, const QString &email, const QString &password, const QDateTime &dateJoined, const bool &isActive);

void TestProfile::create_data()
{
    // definition of test data
    QTest::addColumn<QString>("firstName");
    QTest::addColumn<QString>("lastName");
    QTest::addColumn<QString>("nickname");
    QTest::addColumn<QString>("email");
    QTest::addColumn<QString>("password");
    QTest::addColumn<QDateTime>("dateJoined");
    QTest::addColumn<bool>("isActive");

    // adding to test data
    QTest::newRow("No1") << "oleg" << "stirt" << "lubitel_matana" << "ol_st@kek.ru" << "ter_ver_top" << QDateTime(QDate(2007,3,15)) << true ;
    QTest::newRow("No2") << "daniel" << "zashihin" << "nelubitel_matana" << "da_za@trolling.proizoshol" << "ter_ver_ne_och" << QDateTime(QDate(2013,10,01)) << true ;
}

void TestProfile::create()
{
    // acquisition of test data
    QFETCH(QString, firstName);
    QFETCH(QString, lastName);
    QFETCH(QString, nickname);
    QFETCH(QString, email);
    QFETCH(QString, password);
    QFETCH(QDateTime, dateJoined);
    QFETCH(bool, isActive);

    // logic of the test
    Profile created = Profile::create(firstName, lastName, nickname, email, password, dateJoined, isActive);
    int id = created.userId();
    Profile profile = Profile::get(id);  // Getting model ID

    // verification of result execution
    QCOMPARE(profile.firstName(), title);
    QCOMPARE(profile.lastName(), description);
    QCOMPARE(profile.nickname(), startTime);
    QCOMPARE(profile.email(), finishTime);
    QCOMPARE(profile.password(), isPrivate);
    QCOMPARE(profile.isActive(), isActive);
}

TF_TEST_MAIN(TestProfile)   // specify the class name you created
#include "testprofile.moc"  // charm. Make the extension .moc
