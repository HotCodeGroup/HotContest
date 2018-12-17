#ifndef MESSAGE_H
#define MESSAGE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MessageObject;
class QJsonArray;


class T_MODEL_EXPORT Message : public TAbstractModel
{
public:
    Message();
    Message(const Message &other);
    Message(const MessageObject &object);
    ~Message();

    int messageId() const;
    QString text() const;
    void setText(const QString &text);
    QDateTime timeStamp() const;
    void setTimeStamp(const QDateTime &timeStamp);
    int authorId() const;
    void setAuthorId(int authorId);
    int contestId() const;
    void setContestId(int contestId);
    int lockRevision() const;
    Message &operator=(const Message &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Message create(const QString &text, const QDateTime &timeStamp, int authorId, int contestId);
    static Message create(const QVariantMap &values);
    static Message get(int messageId);
    static Message get(int messageId, int lockRevision);
    static int count();
    static QList<Message> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<MessageObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Message &model);
    friend QDataStream &operator>>(QDataStream &ds, Message &model);
};

Q_DECLARE_METATYPE(Message)
Q_DECLARE_METATYPE(QList<Message>)

#endif // MESSAGE_H
