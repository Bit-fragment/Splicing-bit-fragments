package cn.wh.mode.pojo;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.util.Date;

/**
 * 
 * @TableName article
 */
@TableName(value ="article")
public class Article implements Serializable {
    /**
     * 
     */
    @TableId(type = IdType.AUTO)
    private Long id;

    /**
     * 文章标题
     */
    private String articleTitle;

    /**
     * 文章简介
     */
    private String articleSynopsis;

    /**
     * 发表者id
     */
    private Long userId;

    /**
     * 文章主体文件所在路径(url)
     */
    private String txtUrl;

    /**
     * 文章发表时间
     */
    private Date issuingTime;

    /**
     * 文章最后更新时间
     */
    private Date updateTime;

    /**
     * 文章点赞数
     */
    private Long likeNumber;

    /**
     * 文章收藏数
     */
    private Long favoritesNumber;

    /**
     * 文章评论数
     */
    private Long commentsNumber;

    /**
     * 逻辑删除0未删除、1已删除
     */
    private Integer logicalDeletion;

    /**
     * 可浏览此文章的用户类型(0全可/1会员/2登录可见/3仅自己可见)
     */
    private Integer userType;

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
     * 文章标题
     */
    public String getArticleTitle() {
        return articleTitle;
    }

    /**
     * 文章标题
     */
    public void setArticleTitle(String articleTitle) {
        this.articleTitle = articleTitle;
    }

    /**
     * 文章简介
     */
    public String getArticleSynopsis() {
        return articleSynopsis;
    }

    /**
     * 文章简介
     */
    public void setArticleSynopsis(String articleSynopsis) {
        this.articleSynopsis = articleSynopsis;
    }

    /**
     * 发表者id
     */
    public Long getUserId() {
        return userId;
    }

    /**
     * 发表者id
     */
    public void setUserId(Long userId) {
        this.userId = userId;
    }

    /**
     * 文章主体文件所在路径(url)
     */
    public String getTxtUrl() {
        return txtUrl;
    }

    /**
     * 文章主体文件所在路径(url)
     */
    public void setTxtUrl(String txtUrl) {
        this.txtUrl = txtUrl;
    }

    /**
     * 文章发表时间
     */
    public Date getIssuingTime() {
        return issuingTime;
    }

    /**
     * 文章发表时间
     */
    public void setIssuingTime(Date issuingTime) {
        this.issuingTime = issuingTime;
    }

    /**
     * 文章最后更新时间
     */
    public Date getUpdateTime() {
        return updateTime;
    }

    /**
     * 文章最后更新时间
     */
    public void setUpdateTime(Date updateTime) {
        this.updateTime = updateTime;
    }

    /**
     * 文章点赞数
     */
    public Long getLikeNumber() {
        return likeNumber;
    }

    /**
     * 文章点赞数
     */
    public void setLikeNumber(Long likeNumber) {
        this.likeNumber = likeNumber;
    }

    /**
     * 文章收藏数
     */
    public Long getFavoritesNumber() {
        return favoritesNumber;
    }

    /**
     * 文章收藏数
     */
    public void setFavoritesNumber(Long favoritesNumber) {
        this.favoritesNumber = favoritesNumber;
    }

    /**
     * 文章评论数
     */
    public Long getCommentsNumber() {
        return commentsNumber;
    }

    /**
     * 文章评论数
     */
    public void setCommentsNumber(Long commentsNumber) {
        this.commentsNumber = commentsNumber;
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

    /**
     * 可浏览此文章的用户类型(0全可/1会员/2登录可见/3仅自己可见)
     */
    public Integer getUserType() {
        return userType;
    }

    /**
     * 可浏览此文章的用户类型(0全可/1会员/2登录可见/3仅自己可见)
     */
    public void setUserType(Integer userType) {
        this.userType = userType;
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
        Article other = (Article) that;
        return (this.getId() == null ? other.getId() == null : this.getId().equals(other.getId()))
            && (this.getArticleTitle() == null ? other.getArticleTitle() == null : this.getArticleTitle().equals(other.getArticleTitle()))
            && (this.getArticleSynopsis() == null ? other.getArticleSynopsis() == null : this.getArticleSynopsis().equals(other.getArticleSynopsis()))
            && (this.getUserId() == null ? other.getUserId() == null : this.getUserId().equals(other.getUserId()))
            && (this.getTxtUrl() == null ? other.getTxtUrl() == null : this.getTxtUrl().equals(other.getTxtUrl()))
            && (this.getIssuingTime() == null ? other.getIssuingTime() == null : this.getIssuingTime().equals(other.getIssuingTime()))
            && (this.getUpdateTime() == null ? other.getUpdateTime() == null : this.getUpdateTime().equals(other.getUpdateTime()))
            && (this.getLikeNumber() == null ? other.getLikeNumber() == null : this.getLikeNumber().equals(other.getLikeNumber()))
            && (this.getFavoritesNumber() == null ? other.getFavoritesNumber() == null : this.getFavoritesNumber().equals(other.getFavoritesNumber()))
            && (this.getCommentsNumber() == null ? other.getCommentsNumber() == null : this.getCommentsNumber().equals(other.getCommentsNumber()))
            && (this.getLogicalDeletion() == null ? other.getLogicalDeletion() == null : this.getLogicalDeletion().equals(other.getLogicalDeletion()))
            && (this.getUserType() == null ? other.getUserType() == null : this.getUserType().equals(other.getUserType()));
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((getId() == null) ? 0 : getId().hashCode());
        result = prime * result + ((getArticleTitle() == null) ? 0 : getArticleTitle().hashCode());
        result = prime * result + ((getArticleSynopsis() == null) ? 0 : getArticleSynopsis().hashCode());
        result = prime * result + ((getUserId() == null) ? 0 : getUserId().hashCode());
        result = prime * result + ((getTxtUrl() == null) ? 0 : getTxtUrl().hashCode());
        result = prime * result + ((getIssuingTime() == null) ? 0 : getIssuingTime().hashCode());
        result = prime * result + ((getUpdateTime() == null) ? 0 : getUpdateTime().hashCode());
        result = prime * result + ((getLikeNumber() == null) ? 0 : getLikeNumber().hashCode());
        result = prime * result + ((getFavoritesNumber() == null) ? 0 : getFavoritesNumber().hashCode());
        result = prime * result + ((getCommentsNumber() == null) ? 0 : getCommentsNumber().hashCode());
        result = prime * result + ((getLogicalDeletion() == null) ? 0 : getLogicalDeletion().hashCode());
        result = prime * result + ((getUserType() == null) ? 0 : getUserType().hashCode());
        return result;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(getClass().getSimpleName());
        sb.append(" [");
        sb.append("Hash = ").append(hashCode());
        sb.append(", id=").append(id);
        sb.append(", articleTitle=").append(articleTitle);
        sb.append(", articleSynopsis=").append(articleSynopsis);
        sb.append(", userId=").append(userId);
        sb.append(", txtUrl=").append(txtUrl);
        sb.append(", issuingTime=").append(issuingTime);
        sb.append(", updateTime=").append(updateTime);
        sb.append(", likeNumber=").append(likeNumber);
        sb.append(", favoritesNumber=").append(favoritesNumber);
        sb.append(", commentsNumber=").append(commentsNumber);
        sb.append(", logicalDeletion=").append(logicalDeletion);
        sb.append(", userType=").append(userType);
        sb.append(", serialVersionUID=").append(serialVersionUID);
        sb.append("]");
        return sb.toString();
    }
}