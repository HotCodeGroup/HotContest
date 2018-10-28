#include <TfTest/TfTest>
#include "models/contest.h"    //  include the model class

class TestContest : public QObject
{
    Q_OBJECT
private slots:
    void create_data();
    void create();
};

void TestContest::create_data()
{
    // definition of test data
    QTest::addColumn<QString>("title");
    QTest::addColumn<QString>("description");
    QTest::addColumn<QDateTime>("startTime");
    QTest::addColumn<QDateTime>("finishTime");
    QTest::addColumn<bool>("isPrivate");
    QTest::addColumn<bool>("isActive");
    // adding to test data
    QTest::newRow("No1") << "test contest" << "contest for sosatels" << QDateTime(QDate(2007,3,14)) << QDateTime(QDate(2007,3,15)) << true << true;
    QTest::newRow("No2") << "test contest 1" << "contest for sosatels" << QDateTime(QDate(2007,3,14)) << QDateTime(QDate(2007,3,15)) << true << true;
}

void TestContest::create()
{
    // acquisition of test data
    QFETCH(QString, title);
    QFETCH(QString, description);
    QFETCH(QDateTime, startTime);
    QFETCH(QDateTime, finishTime);
    QFETCH(bool, isPrivate);
    QFETCH(bool, isActive);

    // logic of the test
    Contest created = Contest::create(title, description, startTime,finishTime, isPrivate, isActive);
    int id = created.contestId();
    Contest contest = Contest::get(id);  // Getting model ID

    // verification of result execution
    QCOMPARE(contest.title(), title);
    QCOMPARE(contest.description(), description);
    QCOMPARE(contest.startTime(), startTime);
    QCOMPARE(contest.finishTime(), finishTime);
    QCOMPARE(contest.isPrivate(), isPrivate);
    QCOMPARE(contest.isActive(), isActive);
}

TF_TEST_MAIN(TestContest)   // specify the class name you created
#include "testcontest.moc"  // charm. Make the extension .moc
