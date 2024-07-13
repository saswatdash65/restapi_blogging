/**
 *
 *  Articles.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Articles.h"
#include "Users.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::blogweb;

const std::string Articles::Cols::_id = "id";
const std::string Articles::Cols::_content = "content";
const std::string Articles::Cols::_published = "published";
const std::string Articles::Cols::_authorId = "authorId";
const std::string Articles::Cols::_title = "title";
const std::string Articles::primaryKeyName = "id";
const bool Articles::hasPrimaryKey = true;
const std::string Articles::tableName = "articles";

const std::vector<typename Articles::MetaData> Articles::metaData_={
{"id","std::string","text",0,0,1,1},
{"content","std::string","text",0,0,0,1},
{"published","bool","boolean",1,0,0,1},
{"authorId","std::string","text",0,0,0,1},
{"title","std::string","text",0,0,0,1}
};
const std::string &Articles::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Articles::Articles(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<std::string>(r["id"].as<std::string>());
        }
        if(!r["content"].isNull())
        {
            content_=std::make_shared<std::string>(r["content"].as<std::string>());
        }
        if(!r["published"].isNull())
        {
            published_=std::make_shared<bool>(r["published"].as<bool>());
        }
        if(!r["authorId"].isNull())
        {
            authorid_=std::make_shared<std::string>(r["authorId"].as<std::string>());
        }
        if(!r["title"].isNull())
        {
            title_=std::make_shared<std::string>(r["title"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 5 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            content_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            published_=std::make_shared<bool>(r[index].as<bool>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            authorid_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            title_=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

Articles::Articles(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 5)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            content_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            published_=std::make_shared<bool>(pJson[pMasqueradingVector[2]].asBool());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            authorid_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            title_=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
        }
    }
}

Articles::Articles(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<std::string>(pJson["id"].asString());
        }
    }
    if(pJson.isMember("content"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["content"].isNull())
        {
            content_=std::make_shared<std::string>(pJson["content"].asString());
        }
    }
    if(pJson.isMember("published"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["published"].isNull())
        {
            published_=std::make_shared<bool>(pJson["published"].asBool());
        }
    }
    if(pJson.isMember("authorId"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["authorId"].isNull())
        {
            authorid_=std::make_shared<std::string>(pJson["authorId"].asString());
        }
    }
    if(pJson.isMember("title"))
    {
        dirtyFlag_[4]=true;
        if(!pJson["title"].isNull())
        {
            title_=std::make_shared<std::string>(pJson["title"].asString());
        }
    }
}

void Articles::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 5)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            content_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            published_=std::make_shared<bool>(pJson[pMasqueradingVector[2]].asBool());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            authorid_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            title_=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
        }
    }
}

void Articles::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<std::string>(pJson["id"].asString());
        }
    }
    if(pJson.isMember("content"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["content"].isNull())
        {
            content_=std::make_shared<std::string>(pJson["content"].asString());
        }
    }
    if(pJson.isMember("published"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["published"].isNull())
        {
            published_=std::make_shared<bool>(pJson["published"].asBool());
        }
    }
    if(pJson.isMember("authorId"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["authorId"].isNull())
        {
            authorid_=std::make_shared<std::string>(pJson["authorId"].asString());
        }
    }
    if(pJson.isMember("title"))
    {
        dirtyFlag_[4] = true;
        if(!pJson["title"].isNull())
        {
            title_=std::make_shared<std::string>(pJson["title"].asString());
        }
    }
}

const std::string &Articles::getValueOfId() const noexcept
{
    static const std::string defaultValue = std::string();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Articles::getId() const noexcept
{
    return id_;
}
void Articles::setId(const std::string &pId) noexcept
{
    id_ = std::make_shared<std::string>(pId);
    dirtyFlag_[0] = true;
}
void Articles::setId(std::string &&pId) noexcept
{
    id_ = std::make_shared<std::string>(std::move(pId));
    dirtyFlag_[0] = true;
}
const typename Articles::PrimaryKeyType & Articles::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Articles::getValueOfContent() const noexcept
{
    static const std::string defaultValue = std::string();
    if(content_)
        return *content_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Articles::getContent() const noexcept
{
    return content_;
}
void Articles::setContent(const std::string &pContent) noexcept
{
    content_ = std::make_shared<std::string>(pContent);
    dirtyFlag_[1] = true;
}
void Articles::setContent(std::string &&pContent) noexcept
{
    content_ = std::make_shared<std::string>(std::move(pContent));
    dirtyFlag_[1] = true;
}

const bool &Articles::getValueOfPublished() const noexcept
{
    static const bool defaultValue = bool();
    if(published_)
        return *published_;
    return defaultValue;
}
const std::shared_ptr<bool> &Articles::getPublished() const noexcept
{
    return published_;
}
void Articles::setPublished(const bool &pPublished) noexcept
{
    published_ = std::make_shared<bool>(pPublished);
    dirtyFlag_[2] = true;
}

const std::string &Articles::getValueOfAuthorid() const noexcept
{
    static const std::string defaultValue = std::string();
    if(authorid_)
        return *authorid_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Articles::getAuthorid() const noexcept
{
    return authorid_;
}
void Articles::setAuthorid(const std::string &pAuthorid) noexcept
{
    authorid_ = std::make_shared<std::string>(pAuthorid);
    dirtyFlag_[3] = true;
}
void Articles::setAuthorid(std::string &&pAuthorid) noexcept
{
    authorid_ = std::make_shared<std::string>(std::move(pAuthorid));
    dirtyFlag_[3] = true;
}

const std::string &Articles::getValueOfTitle() const noexcept
{
    static const std::string defaultValue = std::string();
    if(title_)
        return *title_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Articles::getTitle() const noexcept
{
    return title_;
}
void Articles::setTitle(const std::string &pTitle) noexcept
{
    title_ = std::make_shared<std::string>(pTitle);
    dirtyFlag_[4] = true;
}
void Articles::setTitle(std::string &&pTitle) noexcept
{
    title_ = std::make_shared<std::string>(std::move(pTitle));
    dirtyFlag_[4] = true;
}

void Articles::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Articles::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "id",
        "content",
        "published",
        "authorId",
        "title"
    };
    return inCols;
}

void Articles::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getId())
        {
            binder << getValueOfId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getContent())
        {
            binder << getValueOfContent();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getPublished())
        {
            binder << getValueOfPublished();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getAuthorid())
        {
            binder << getValueOfAuthorid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getTitle())
        {
            binder << getValueOfTitle();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Articles::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[0])
    {
        ret.push_back(getColumnName(0));
    }
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    if(dirtyFlag_[4])
    {
        ret.push_back(getColumnName(4));
    }
    return ret;
}

void Articles::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getId())
        {
            binder << getValueOfId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getContent())
        {
            binder << getValueOfContent();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getPublished())
        {
            binder << getValueOfPublished();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getAuthorid())
        {
            binder << getValueOfAuthorid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getTitle())
        {
            binder << getValueOfTitle();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Articles::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getContent())
    {
        ret["content"]=getValueOfContent();
    }
    else
    {
        ret["content"]=Json::Value();
    }
    if(getPublished())
    {
        ret["published"]=getValueOfPublished();
    }
    else
    {
        ret["published"]=Json::Value();
    }
    if(getAuthorid())
    {
        ret["authorId"]=getValueOfAuthorid();
    }
    else
    {
        ret["authorId"]=Json::Value();
    }
    if(getTitle())
    {
        ret["title"]=getValueOfTitle();
    }
    else
    {
        ret["title"]=Json::Value();
    }
    return ret;
}

Json::Value Articles::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 5)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getContent())
            {
                ret[pMasqueradingVector[1]]=getValueOfContent();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getPublished())
            {
                ret[pMasqueradingVector[2]]=getValueOfPublished();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getAuthorid())
            {
                ret[pMasqueradingVector[3]]=getValueOfAuthorid();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getTitle())
            {
                ret[pMasqueradingVector[4]]=getValueOfTitle();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getContent())
    {
        ret["content"]=getValueOfContent();
    }
    else
    {
        ret["content"]=Json::Value();
    }
    if(getPublished())
    {
        ret["published"]=getValueOfPublished();
    }
    else
    {
        ret["published"]=Json::Value();
    }
    if(getAuthorid())
    {
        ret["authorId"]=getValueOfAuthorid();
    }
    else
    {
        ret["authorId"]=Json::Value();
    }
    if(getTitle())
    {
        ret["title"]=getValueOfTitle();
    }
    else
    {
        ret["title"]=Json::Value();
    }
    return ret;
}

bool Articles::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    else
    {
        err="The id column cannot be null";
        return false;
    }
    if(pJson.isMember("content"))
    {
        if(!validJsonOfField(1, "content", pJson["content"], err, true))
            return false;
    }
    else
    {
        err="The content column cannot be null";
        return false;
    }
    if(pJson.isMember("published"))
    {
        if(!validJsonOfField(2, "published", pJson["published"], err, true))
            return false;
    }
    if(pJson.isMember("authorId"))
    {
        if(!validJsonOfField(3, "authorId", pJson["authorId"], err, true))
            return false;
    }
    else
    {
        err="The authorId column cannot be null";
        return false;
    }
    if(pJson.isMember("title"))
    {
        if(!validJsonOfField(4, "title", pJson["title"], err, true))
            return false;
    }
    else
    {
        err="The title column cannot be null";
        return false;
    }
    return true;
}
bool Articles::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                  const std::vector<std::string> &pMasqueradingVector,
                                                  std::string &err)
{
    if(pMasqueradingVector.size() != 5)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[0] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[3] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[4].empty())
      {
          if(pJson.isMember(pMasqueradingVector[4]))
          {
              if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[4] + " column cannot be null";
            return false;
        }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Articles::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("content"))
    {
        if(!validJsonOfField(1, "content", pJson["content"], err, false))
            return false;
    }
    if(pJson.isMember("published"))
    {
        if(!validJsonOfField(2, "published", pJson["published"], err, false))
            return false;
    }
    if(pJson.isMember("authorId"))
    {
        if(!validJsonOfField(3, "authorId", pJson["authorId"], err, false))
            return false;
    }
    if(pJson.isMember("title"))
    {
        if(!validJsonOfField(4, "title", pJson["title"], err, false))
            return false;
    }
    return true;
}
bool Articles::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                std::string &err)
{
    if(pMasqueradingVector.size() != 5)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
      if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
      {
          if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Articles::validJsonOfField(size_t index,
                                const std::string &fieldName,
                                const Json::Value &pJson,
                                std::string &err,
                                bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 2:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isBool())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 3:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 4:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
    }
    return true;
}
Users Articles::getUser(const DbClientPtr &clientPtr) const {
    static const std::string sql = "select * from users where authorId = $1";
    Result r(nullptr);
    {
        auto binder = *clientPtr << sql;
        binder << *id_ << Mode::Blocking >>
            [&r](const Result &result) { r = result; };
        binder.exec();
    }
    if (r.size() == 0)
    {
        throw UnexpectedRows("0 rows found");
    }
    else if (r.size() > 1)
    {
        throw UnexpectedRows("Found more than one row");
    }
    return Users(r[0]);
}

void Articles::getUser(const DbClientPtr &clientPtr,
                       const std::function<void(Users)> &rcb,
                       const ExceptionCallback &ecb) const
{
    static const std::string sql = "select * from users where authorId = $1";
    *clientPtr << sql
               << *id_
               >> [rcb = std::move(rcb), ecb](const Result &r){
                    if (r.size() == 0)
                    {
                        ecb(UnexpectedRows("0 rows found"));
                    }
                    else if (r.size() > 1)
                    {
                        ecb(UnexpectedRows("Found more than one row"));
                    }
                    else
                    {
                        rcb(Users(r[0]));
                    }
               }
               >> ecb;
}
