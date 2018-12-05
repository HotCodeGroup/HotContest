#include <TfTest/TfTest>
#include "models/test.h"    //  include the model class

class TestProfile : public QObject
{
    Q_OBJECT
private slots:
    void create_data();
    void create();
};

void TestTest::create_data()
{
    // definition of test data
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("output");
    QTest::addColumn<int>("problemId");

    // adding to test data
    QTest::newRow("No1") << "lsakasgags" << "asfsf" << 1;
    QTest::newRow("No2") << "bolee osmislenniy input" << "bolee osmislenniy output" << 2;
}

void TestTest::create()
{
    // acquisition of test data
    QFETCH(QString, input);
    QFETCH(QString, output);
    QFETCH(int, problemId);

    // logic of the test
    Test created = Test::create(input, output, problemId);
    int id = created.testId();
    Test test = Test::get(id);  // Getting model ID

    // verification of result execution
    QCOMPARE(test.input(), input);
    QCOMPARE(test.output(), output);
    QCOMPARE(test.problemId(), problemId);
}

TF_TEST_MAIN(TestSubmit)   // specify the class name you created
#include "testtest.moc"  // charm. Make the extension .moc
