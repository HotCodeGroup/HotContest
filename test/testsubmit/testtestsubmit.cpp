#include <TfTest/TfTest>
#include "models/testsubmit.h"    //  include the model class

class TestProfile : public QObject
{
    Q_OBJECT
private slots:
    void create_data();
    void create();
};
(const QString &verdict, int time, int memory, int testId, int submitId)
void TestTestSubmit::create_data()
{
    // definition of test data
    QTest::addColumn<QString>("verdict");
    QTest::addColumn<int>("time");
    QTest::addColumn<int>("memory");
    QTest::addColumn<int>("testId");
    QTest::addColumn<int>("submitId");

    // adding to test data
    QTest::newRow("No1") << "OK" << 255 << 20000 << 1 << 1;
    QTest::newRow("No2") << "MEM_LIM" << 500 << 1000000 << 2 << 1;
}

void TestTestSubmit::create()
{
    // acquisition of test data
    QFETCH(QString, verdict);
    QFETCH(int, time_p);
    QFETCH(int, memory);
    QFETCH(int, testId);
    QFETCH(int, submitId);

    // logic of the test
    TestTestSubmit created = TestTestSubmit::create(verdict, time_p, memory, testId, submitId);
    int id = created.submitId();
    TestTestSubmit testsubmit = TestTestSubmit::get(id);  // Getting model ID

    // verification of result execution
    QCOMPARE(testsubmit.verdict(), verdict);
    QCOMPARE(testsubmit.time(), time_p);
    QCOMPARE(testsubmit.memory(), memory);
    QCOMPARE(testsubmit.testId(), testId);
    QCOMPARE(testsubmit.submitId(), submitId);

}

TF_TEST_MAIN(TestTestSubmit)   // specify the class name you created
#include "testtestsubmit.moc"  // charm. Make the extension .moc
