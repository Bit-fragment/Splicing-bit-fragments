package cn.wh.mode.pojo;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;

/**
 * 
 * @TableName movie
 */
@TableName(value ="movie")
public class Movie implements Serializable {
    /**
     * 
     */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /**
     * 电影名
     */
    private String movieName;

    /**
     * 存储路径
     */
    private String movieUrl;

    /**
     * 分类字段
     */
    private String movieSort;

    /**
     * 是否隐藏 0:未隐藏 1:已隐藏
     */
    private Integer movieHide;

    /**
     * 逻辑删除 0:未删除 1:已删除
     */
    private Integer movieDelete;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;

    /**
     * 
     */
    public Integer getId() {
        return id;
    }

    /**
     * 
     */
    public void setId(Integer id) {
        this.id = id;
    }

    /**
     * 电影名
     */
    public String getMovieName() {
        return movieName;
    }

    /**
     * 电影名
     */
    public void setMovieName(String movieName) {
        this.movieName = movieName;
    }

    /**
     * 存储路径
     */
    public String getMovieUrl() {
        return movieUrl;
    }

    /**
     * 存储路径
     */
    public void setMovieUrl(String movieUrl) {
        this.movieUrl = movieUrl;
    }

    /**
     * 分类字段
     */
    public String getMovieSort() {
        return movieSort;
    }

    /**
     * 分类字段
     */
    public void setMovieSort(String movieSort) {
        this.movieSort = movieSort;
    }

    /**
     * 是否隐藏 0:未隐藏 1:已隐藏
     */
    public Integer getMovieHide() {
        return movieHide;
    }

    /**
     * 是否隐藏 0:未隐藏 1:已隐藏
     */
    public void setMovieHide(Integer movieHide) {
        this.movieHide = movieHide;
    }

    /**
     * 逻辑删除 0:未删除 1:已删除
     */
    public Integer getMovieDelete() {
        return movieDelete;
    }

    /**
     * 逻辑删除 0:未删除 1:已删除
     */
    public void setMovieDelete(Integer movieDelete) {
        this.movieDelete = movieDelete;
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
        Movie other = (Movie) that;
        return (this.getId() == null ? other.getId() == null : this.getId().equals(other.getId()))
            && (this.getMovieName() == null ? other.getMovieName() == null : this.getMovieName().equals(other.getMovieName()))
            && (this.getMovieUrl() == null ? other.getMovieUrl() == null : this.getMovieUrl().equals(other.getMovieUrl()))
            && (this.getMovieSort() == null ? other.getMovieSort() == null : this.getMovieSort().equals(other.getMovieSort()))
            && (this.getMovieHide() == null ? other.getMovieHide() == null : this.getMovieHide().equals(other.getMovieHide()))
            && (this.getMovieDelete() == null ? other.getMovieDelete() == null : this.getMovieDelete().equals(other.getMovieDelete()));
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((getId() == null) ? 0 : getId().hashCode());
        result = prime * result + ((getMovieName() == null) ? 0 : getMovieName().hashCode());
        result = prime * result + ((getMovieUrl() == null) ? 0 : getMovieUrl().hashCode());
        result = prime * result + ((getMovieSort() == null) ? 0 : getMovieSort().hashCode());
        result = prime * result + ((getMovieHide() == null) ? 0 : getMovieHide().hashCode());
        result = prime * result + ((getMovieDelete() == null) ? 0 : getMovieDelete().hashCode());
        return result;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(getClass().getSimpleName());
        sb.append(" [");
        sb.append("Hash = ").append(hashCode());
        sb.append(", id=").append(id);
        sb.append(", movieName=").append(movieName);
        sb.append(", movieUrl=").append(movieUrl);
        sb.append(", movieSort=").append(movieSort);
        sb.append(", movieHide=").append(movieHide);
        sb.append(", movieDelete=").append(movieDelete);
        sb.append(", serialVersionUID=").append(serialVersionUID);
        sb.append("]");
        return sb.toString();
    }
}