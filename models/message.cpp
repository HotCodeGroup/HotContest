#include <TreeFrogModel>
#include "message.h"
#include "messageobject.h"

Message::Message()
    : TAbstractModel(), d(new MessageObject())
{
    d->message_id = 0;
    d->author_id = 0;
    d->contest_id = 0;
    d->lock_revision = 0;
}

Message::Message(const Message &other)
    : TAbstractModel(), d(new MessageObject(*other.d))
{ }

Message::Message(const MessageObject &object)
    : TAbstractModel(), d(new MessageObject(object))
{ }

Message::~Message()
{
    // If the reference count becomes 0,
    // the shared data object 'MessageObject' is deleted.
}

int Message::messageId() const
{
    return d->message_id;
}

QString Message::text() const
{
    return d->text;
}

void Message::setText(const QString &text)
{
    d->text = text;
}

QDateTime Message::timeStamp() const
{
    return d->time_stamp;
}

void Message::setTimeStamp(const QDateTime &timeStamp)
{
    d->time_stamp = timeStamp;
}

int Message::authorId() const
{
    return d->author_id;
}

void Message::setAuthorId(int authorId)
{
    d->author_id = authorId;
}

int Message::contestId() const
{
    return d->contest_id;
}

void Message::setContestId(int contestId)
{
    d->contest_id = contestId;
}

int Message::lockRevision() const
{
    return d->lock_revision;
}

Message &Message::operator=(const Message &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Message Message::create(const QString &text, const QDateTime &timeStamp, int authorId, int contestId)
{
    MessageObject obj;
    obj.text = text;
    obj.time_stamp = timeStamp;
    obj.author_id = authorId;
    obj.contest_id = contestId;
    if (!obj.create()) {
        return Message();
    }
    return Message(obj);
}

Message Message::create(const QVariantMap &values)
{
    Message model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Message Message::get(int messageId)
{
    TSqlORMapper<MessageObject> mapper;
    return Message(mapper.findByPrimaryKey(messageId));
}

Message Message::get(int messageId, int lockRevision)
{
    TSqlORMapper<MessageObject> mapper;
    TCriteria cri;
    cri.add(MessageObject::MessageId, messageId);
    cri.add(MessageObject::LockRevision, lockRevision);
    return Message(mapper.findFirst(cri));
}

int Message::count()
{
    TSqlORMapper<MessageObject> mapper;
    return mapper.findCount();
}

QList<Message> Message::getAll()
{
    return tfGetModelListByCriteria<Message, MessageObject>(TCriteria());
}

QJsonArray Message::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<MessageObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<MessageObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Message(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Message::modelData()
{
    return d.data();
}

const TModelObject *Message::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Message &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Message &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Message)
