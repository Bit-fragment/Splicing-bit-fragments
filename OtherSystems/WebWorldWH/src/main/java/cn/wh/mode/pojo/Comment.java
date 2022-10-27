package cn.wh.mode.pojo;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.util.Date;

/**
 * 
 * @TableName comment
 */
@TableName(value ="comment")
public class Comment implements Serializable {
    /**
     * 
     */
    @TableId(type = IdType.AUTO)
    private Long id;

    /**
     * 发表评论者id
     */
    private Long userId;

    /**
     * 被@者id
     */
    private Long objectId;

    /**
     * 所属文章id
     */
    private Long articleId;

    /**
     * 回复的评论id
     */
    private Long commentId;

    /**
     * 评论点赞数
     */
    private Long likeNumber;

    /**
     * 评论内容
     */
    private String comments;

    /**
     * 评论发表时间
     */
    private Date issuingTime;

    /**
     * 逻辑删除0未删除、1已删除
     */
    private Integer logicalDeletion;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;

    /**
     * 
     */
    public Long getId() {
        return id;
    }

    /**
     * 
     */
    public void setId(Long id) {
        this.id = id;
    }

    /**
     * 发表评论者id
     */
    public Long getUserId() {
        return userId;
    }

    /**
     * 发表评论者id
     */
    public void setUserId(Long userId) {
        this.userId = userId;
    }

    /**
     * 被@者id
     */
    public Long getObjectId() {
        return objectId;
    }

    /**
     * 被@者id
     */
    public void setObjectId(Long objectId) {
        this.objectId = objectId;
    }

    /**
     * 所属文章id
     */
    public Long getArticleId() {
        return articleId;
    }

    /**
     * 所属文章id
     */
    public void setArticleId(Long articleId) {
        this.articleId = articleId;
    }

    /**
     * 回复的评论id
     */
    public Long getCommentId() {
        return commentId;
    }

    /**
     * 回复的评论id
     */
    public void setCommentId(Long commentId) {
        this.commentId = commentId;
    }

    /**
     * 评论点赞数
     */
    public Long getLikeNumber() {
        return likeNumber;
    }

    /**
     * 评论点赞数
     */
    public void setLikeNumber(Long likeNumber) {
        this.likeNumber = likeNumber;
    }

    /**
     * 评论内容
     */
    public String getComments() {
        return comments;
    }

    /**
     * 评论内容
     */
    public void setComments(String comments) {
        this.comments = comments;
    }

    /**
     * 评论发表时间
     */
    public Date getIssuingTime() {
        return issuingTime;
    }

    /**
     * 评论发表时间
     */
    public void setIssuingTime(Date issuingTime) {
        this.issuingTime = issuingTime;
    }

    /**
     * 逻辑删除0未删除、1已删除
     */
    public Integer getLogicalDeletion() {
        return logicalDeletion;
    }

    /**
     * 逻辑删除0未删除、1已删除
     */
    public void setLogicalDeletion(Integer logicalDeletion) {
        this.logicalDeletion = logicalDeletion;
    }

    @Override
    public boolean equals(Object that) {
        if (this == that) {
            return true;
        }
        if (that == null) {
            return false;
        }
        if (getClass() != that.getClass()) {
            return false;
        }
        Comment other = (Comment) that;
        return (this.getId() == null ? other.getId() == null : this.getId().equals(other.getId()))
            && (this.getUserId() == null ? other.getUserId() == null : this.getUserId().equals(other.getUserId()))
            && (this.getObjectId() == null ? other.getObjectId() == null : this.getObjectId().equals(other.getObjectId()))
            && (this.getArticleId() == null ? other.getArticleId() == null : this.getArticleId().equals(other.getArticleId()))
            && (this.getCommentId() == null ? other.getCommentId() == null : this.getCommentId().equals(other.getCommentId()))
            && (this.getLikeNumber() == null ? other.getLikeNumber() == null : this.getLikeNumber().equals(other.getLikeNumber()))
            && (this.getComments() == null ? other.getComments() == null : this.getComments().equals(other.getComments()))
            && (this.getIssuingTime() == null ? other.getIssuingTime() == null : this.getIssuingTime().equals(other.getIssuingTime()))
            && (this.getLogicalDeletion() == null ? other.getLogicalDeletion() == null : this.getLogicalDeletion().equals(other.getLogicalDeletion()));
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((getId() == null) ? 0 : getId().hashCode());
        result = prime * result + ((getUserId() == null) ? 0 : getUserId().hashCode());
        result = prime * result + ((getObjectId() == null) ? 0 : getObjectId().hashCode());
        result = prime * result + ((getArticleId() == null) ? 0 : getArticleId().hashCode());
        result = prime * result + ((getCommentId() == null) ? 0 : getCommentId().hashCode());
        result = prime * result + ((getLikeNumber() == null) ? 0 : getLikeNumber().hashCode());
        result = prime * result + ((getComments() == null) ? 0 : getComments().hashCode());
        result = prime * result + ((getIssuingTime() == null) ? 0 : getIssuingTime().hashCode());
        result = prime * result + ((getLogicalDeletion() == null) ? 0 : getLogicalDeletion().hashCode());
        return result;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(getClass().getSimpleName());
        sb.append(" [");
        sb.append("Hash = ").append(hashCode());
        sb.append(", id=").append(id);
        sb.append(", userId=").append(userId);
        sb.append(", objectId=").append(objectId);
        sb.append(", articleId=").append(articleId);
        sb.append(", commentId=").append(commentId);
        sb.append(", likeNumber=").append(likeNumber);
        sb.append(", comments=").append(comments);
        sb.append(", issuingTime=").append(issuingTime);
        sb.append(", logicalDeletion=").append(logicalDeletion);
        sb.append(", serialVersionUID=").append(serialVersionUID);
        sb.append("]");
        return sb.toString();
    }
}