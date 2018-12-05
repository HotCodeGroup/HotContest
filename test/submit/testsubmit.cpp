#include <TfTest/TfTest>
#include "models/submit.h"    //  include the model class

class TestSubmit : public QObject
{
    Q_OBJECT
private slots:
    void create_data();
    void create();
};

void TestSubmit::create_data()
{
    // definition of test data
    QTest::addColumn<QString>("respCode");
    QTest::addColumn<int>("errorTest");
    QTest::addColumn<int>("time_p");
    QTest::addColumn<int>("memory");
    QTest::addColumn<int>("solutionId");

    // adding to test data
    QTest::newRow("No1") << "OK" << 0 << 1<< 1<< 1;
    QTest::newRow("No2") << "OK" << 1 << 1<< 1<< 1;
}
void TestSubmit::create()
{
    // acquisition of test data
    QFETCH(QString, respCode);
    QFETCH(int, errorTest);
    QFETCH(int, time_p);
    QFETCH(int, memory);
    QFETCH(int, solutionId);

    // logic of the test
    Submit created = Submit::create(respCode, errorTest, time_p, memory, solutionId);
    int id = created.submitId();
    Submit submit = Submit::get(id);  // Getting model ID

    // verification of result execution
    QCOMPARE(submit.respCode(), title);
    QCOMPARE(submit.errorTest(), description);
    QCOMPARE(submit.time(), time_p);
    QCOMPARE(submit.memory(), memory);
    QCOMPARE(submit.solutionId(), solutionId);
}

TF_TEST_MAIN(TestSubmit)   // specify the class name you created
#include "testsubmit.moc"  // charm. Make the extension .moc
