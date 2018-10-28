#include <TfTest/TfTest>
#include "models/problem.h"    //  include the model class

class TestProblem : public QObject
{
    Q_OBJECT
private slots:
    void create_data();
    void create();
};

void TestProblem::create_data()
{
    // definition of test data
    QTest::addColumn<QString>("title");
    QTest::addColumn<QString>("description");
    QTest::addColumn<int>("timeLimit");
    QTest::addColumn<int>("memoryLimit");
    QTest::addColumn<int>("triesLeft");
    QTest::addColumn<int>("points");
    QTest::addColumn<int>("penaltyTry");
    QTest::addColumn<int>("penaltyTime");
    QTest::addColumn<int>("contestId");

    // adding to test data
    QTest::newRow("No1") << "teask 1" << "problem1 for sosatels" << 1000 << 1000 << 100 << 500 << 25 << 2 << 1;
    QTest::newRow("No2") << "teask 2" << "problem2 for sosatels" << 1000 << 1000 << 100 << 500 << 25 << 2 << 1;
}

void TestProblem::create()
{
    // acquisition of test data
    QFETCH(QString, title);
    QFETCH(QString, description);
    QFETCH(int, timeLimit);
    QFETCH(int, memoryLimit);
    QFETCH(int, triesLeft);
    QFETCH(int, points);
    QFETCH(int, penaltyTry);
    QFETCH(int, penaltyTime);
    QFETCH(int, contestId);

    // logic of the test
    Problem created = Problem::create(title, description, timeLimit, memoryLimit, triesLeft, points, penaltyTry, penaltyTime, contestId);
    int id = created.problemId();
    Problem contest = Problem::get(id);  // Getting model ID

    // verification of result execution
    QCOMPARE(contest.title(), title);
    QCOMPARE(contest.description(), description);
    QCOMPARE(contest.timeLimit(), timeLimit);
    QCOMPARE(contest.memoryLimit(), memoryLimit);
    QCOMPARE(contest.triesLeft(), triesLeft);
    QCOMPARE(contest.points(), points);
    QCOMPARE(contest.penaltyTry(), penaltyTry);
    QCOMPARE(contest.penaltyTime(), penaltyTime);
    QCOMPARE(contest.contestId(), contestId);
}
TF_TEST_MAIN(TestProblem)   // specify the class name you created
#include "testproblem.moc"  // charm. Make the extension .moc
