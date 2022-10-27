package cn.wh.mode.pojo;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.util.Date;

/**
 * 文件表
 * @TableName fileil
 */
@TableName(value ="fileil")
public class Fileil implements Serializable {
    /**
     * 
     */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /**
     * 文件名;不包括扩展名
     */
    private String fileName;

    /**
     * 文件后缀名；默认为.mull
     */
    private String fileSuffix;

    /**
     * 文件储存url
     */
    private String fileUrl;

    /**
     * 文件大小
     */
    private Long fileSize;

    /**
     * 备注
     */
    private String fileRemarks;

    /**
     * 入库时间
     */
    private Date storageDate;

    /**
     * 最后更新时间
     */
    private Date lastUpdated;

    /**
     * 上传者用户id
     */
    private Integer ueserId;

    /**
     * 0:隐藏/1:展示/2:付费
     */
    private Integer fileState;

    /**
     * 付费费用
     */
    private Long fileCost;

    /**
     * 0:未删除/1:已删除
     */
    private Integer deleteType;

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
     * 文件名;不包括扩展名
     */
    public String getFileName() {
        return fileName;
    }

    /**
     * 文件名;不包括扩展名
     */
    public void setFileName(String fileName) {
        this.fileName = fileName;
    }

    /**
     * 文件后缀名；默认为.mull
     */
    public String getFileSuffix() {
        return fileSuffix;
    }

    /**
     * 文件后缀名；默认为.mull
     */
    public void setFileSuffix(String fileSuffix) {
        this.fileSuffix = fileSuffix;
    }

    /**
     * 文件储存url
     */
    public String getFileUrl() {
        return fileUrl;
    }

    /**
     * 文件储存url
     */
    public void setFileUrl(String fileUrl) {
        this.fileUrl = fileUrl;
    }

    /**
     * 文件大小
     */
    public Long getFileSize() {
        return fileSize;
    }

    /**
     * 文件大小
     */
    public void setFileSize(Long fileSize) {
        this.fileSize = fileSize;
    }

    /**
     * 备注
     */
    public String getFileRemarks() {
        return fileRemarks;
    }

    /**
     * 备注
     */
    public void setFileRemarks(String fileRemarks) {
        this.fileRemarks = fileRemarks;
    }

    /**
     * 入库时间
     */
    public Date getStorageDate() {
        return storageDate;
    }

    /**
     * 入库时间
     */
    public void setStorageDate(Date storageDate) {
        this.storageDate = storageDate;
    }

    /**
     * 最后更新时间
     */
    public Date getLastUpdated() {
        return lastUpdated;
    }

    /**
     * 最后更新时间
     */
    public void setLastUpdated(Date lastUpdated) {
        this.lastUpdated = lastUpdated;
    }

    /**
     * 上传者用户id
     */
    public Integer getUeserId() {
        return ueserId;
    }

    /**
     * 上传者用户id
     */
    public void setUeserId(Integer ueserId) {
        this.ueserId = ueserId;
    }

    /**
     * 0:隐藏/1:展示/2:付费
     */
    public Integer getFileState() {
        return fileState;
    }

    /**
     * 0:隐藏/1:展示/2:付费
     */
    public void setFileState(Integer fileState) {
        this.fileState = fileState;
    }

    /**
     * 付费费用
     */
    public Long getFileCost() {
        return fileCost;
    }

    /**
     * 付费费用
     */
    public void setFileCost(Long fileCost) {
        this.fileCost = fileCost;
    }

    /**
     * 0:未删除/1:已删除
     */
    public Integer getDeleteType() {
        return deleteType;
    }

    /**
     * 0:未删除/1:已删除
     */
    public void setDeleteType(Integer deleteType) {
        this.deleteType = deleteType;
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
        Fileil other = (Fileil) that;
        return (this.getId() == null ? other.getId() == null : this.getId().equals(other.getId()))
            && (this.getFileName() == null ? other.getFileName() == null : this.getFileName().equals(other.getFileName()))
            && (this.getFileSuffix() == null ? other.getFileSuffix() == null : this.getFileSuffix().equals(other.getFileSuffix()))
            && (this.getFileUrl() == null ? other.getFileUrl() == null : this.getFileUrl().equals(other.getFileUrl()))
            && (this.getFileSize() == null ? other.getFileSize() == null : this.getFileSize().equals(other.getFileSize()))
            && (this.getFileRemarks() == null ? other.getFileRemarks() == null : this.getFileRemarks().equals(other.getFileRemarks()))
            && (this.getStorageDate() == null ? other.getStorageDate() == null : this.getStorageDate().equals(other.getStorageDate()))
            && (this.getLastUpdated() == null ? other.getLastUpdated() == null : this.getLastUpdated().equals(other.getLastUpdated()))
            && (this.getUeserId() == null ? other.getUeserId() == null : this.getUeserId().equals(other.getUeserId()))
            && (this.getFileState() == null ? other.getFileState() == null : this.getFileState().equals(other.getFileState()))
            && (this.getFileCost() == null ? other.getFileCost() == null : this.getFileCost().equals(other.getFileCost()))
            && (this.getDeleteType() == null ? other.getDeleteType() == null : this.getDeleteType().equals(other.getDeleteType()));
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((getId() == null) ? 0 : getId().hashCode());
        result = prime * result + ((getFileName() == null) ? 0 : getFileName().hashCode());
        result = prime * result + ((getFileSuffix() == null) ? 0 : getFileSuffix().hashCode());
        result = prime * result + ((getFileUrl() == null) ? 0 : getFileUrl().hashCode());
        result = prime * result + ((getFileSize() == null) ? 0 : getFileSize().hashCode());
        result = prime * result + ((getFileRemarks() == null) ? 0 : getFileRemarks().hashCode());
        result = prime * result + ((getStorageDate() == null) ? 0 : getStorageDate().hashCode());
        result = prime * result + ((getLastUpdated() == null) ? 0 : getLastUpdated().hashCode());
        result = prime * result + ((getUeserId() == null) ? 0 : getUeserId().hashCode());
        result = prime * result + ((getFileState() == null) ? 0 : getFileState().hashCode());
        result = prime * result + ((getFileCost() == null) ? 0 : getFileCost().hashCode());
        result = prime * result + ((getDeleteType() == null) ? 0 : getDeleteType().hashCode());
        return result;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(getClass().getSimpleName());
        sb.append(" [");
        sb.append("Hash = ").append(hashCode());
        sb.append(", id=").append(id);
        sb.append(", fileName=").append(fileName);
        sb.append(", fileSuffix=").append(fileSuffix);
        sb.append(", fileUrl=").append(fileUrl);
        sb.append(", fileSize=").append(fileSize);
        sb.append(", fileRemarks=").append(fileRemarks);
        sb.append(", storageDate=").append(storageDate);
        sb.append(", lastUpdated=").append(lastUpdated);
        sb.append(", ueserId=").append(ueserId);
        sb.append(", fileState=").append(fileState);
        sb.append(", fileCost=").append(fileCost);
        sb.append(", deleteType=").append(deleteType);
        sb.append(", serialVersionUID=").append(serialVersionUID);
        sb.append("]");
        return sb.toString();
    }
}