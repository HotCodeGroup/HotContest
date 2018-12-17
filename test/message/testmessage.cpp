#include <TfTest/TfTest>
#include "models/message.h"    //  include the model class

class TestMessage : public QObject
{
    Q_OBJECT
private slots:
    void create_data();
    void create();
};

void TestMessage::create_data()
{
    // definition of test data
    QTest::addColumn<QString>("text");
    QTest::addColumn<QDateTime>("timeStamp");
    QTest::addColumn<int>("authorId");
    QTest::addColumn<int>("messageId");
    // adding to test data
    QTest::newRow("No1") << "ya ne sharu" << QDateTime(QDate(2018,12,1)) << 1 << 2;
    QTest::newRow("No2") << "ya tozhe" << QDateTime(QDate(2018,12,1)) << 1 << 2;;
}

void TestMessage::create()
{
    // acquisition of test data
    QFETCH(QString, text);
    QFETCH(QDateTime, timeStamp);
    QFETCH(bool, authorId);
    QFETCH(bool, messageId);

    // logic of the test
    Message created = Message::create(text, timeStamp, authorId,messageId);
    int id = created.messageId();
    Message message = Message::get(id);  // Getting model ID

    // verification of result execution
    QCOMPARE(message.text(), text);
    QCOMPARE(message.timeStamp(), timeStamp);
    QCOMPARE(message.authorId(), authorId);
    QCOMPARE(message.messageId(), messageId);
}

TF_TEST_MAIN(TestMessage)   // specify the class name you created
#include "testmessage.moc"  // charm. Make the extension .moc
