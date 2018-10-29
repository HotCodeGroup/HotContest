#include <TfTest/TfTest>
#include "models/solution.h"    //  include the model class

class TestProfile : public QObject
{
    Q_OBJECT
private slots:
    void create_data();
    void create();
};

void TestSolution::create_data()
{
    // definition of test data
    QTest::addColumn<QString>("srcFile");
    QTest::addColumn<QDateTime>("submitTime");
    QTest::addColumn<int>("problemId");
    QTest::addColumn<int>("userId");

    // adding to test data
    QTest::newRow("No1") << "afs" << QDateTime(QDate(2015,4,16)) << 1 << 1;
    QTest::newRow("No2") << "afs" << QDateTime(QDate(2014,1,9)) << 1 << 2;
}

void TestSolution::create()
{
    // acquisition of test data
    QFETCH(QString, srcFile);
    QFETCH(QDateTime, submitTime);
    QFETCH(int, problemId);
    QFETCH(int, userId);

    // logic of the test
    Solution created = Solution::create(src_file, submitTime, problemId, userId);
    int id = created.solutionId();
    Solution solution = Solution::get(id);  // Getting model ID

    // verification of result execution
    QCOMPARE(solution.src_file(), src_file);
    QCOMPARE(solution.submitTime(), submitTime);
    QCOMPARE(solution.problemId(), problemId);
    QCOMPARE(solution.userId(), userId);
}

TF_TEST_MAIN(TestSolution)   // specify the class name you created
#include "testsolution.moc"  // charm. Make the extension .moc
