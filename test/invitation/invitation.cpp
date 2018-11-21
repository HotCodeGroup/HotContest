#include <TfTest/TfTest>
#include "models/invitation.h"    //  include the model class

class TestProfile : public QObject
{
    Q_OBJECT
private slots:
    void create_data();
    void create();
};

void TestInvitation::create_data()
{
    // definition of test data
    QTest::addColumn<int>("state");
    QTest::addColumn<int>("senderId");
    QTest::addColumn<int>("addresseId");
    QTest::addColumn<int>("contestId");

    // adding to test data
    QTest::newRow("No1") << 1 << 1 << 2 << 1;
    QTest::newRow("No2") << 0 << 2 << 1 << 2;
}

void TestInvitation::create()
{
    // acquisition of test data
    QFETCH(int, state);
    QFETCH(int, senderId);
    QFETCH(int, addresseId);
    QFETCH(int, contestId);

    // logic of the test
    Invitation created = Invitation::create(state, senderId, addresseId, contestId);
    int id = created.invitationId();
    Invitation invitation = Invitation::get(id);  // Getting model ID

    // verification of result execution
    QCOMPARE(invitation.state(), state);
    QCOMPARE(invitation.senderId(), senderId);
    QCOMPARE(invitation.addresseId(), addresseId);
    QCOMPARE(invitation.contestId(), contestId);
}

TF_TEST_MAIN(TestInvitation)   // specify the class name you created
#include "testinvitation.moc"  // charm. Make the extension .moc
