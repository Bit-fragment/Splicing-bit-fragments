package cn.wh.mode.pojo;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;

/**
 * 
 * @TableName user
 */
@TableName(value ="user")
public class User implements Serializable {
    /**
     * 
     */
    @TableId(type = IdType.AUTO)
    private Long id;

    /**
     * 昵称
     */
    private String username;

    /**
     * 账号
     */
    private String account;

    /**
     * 密码
     */
    private String password;

    /**
     * 余额
     */
    private Integer balance;

    /**
     * 秘钥(用来加密可加密的字段)
     */
    private String userKey;

    /**
     * 用户类型0普通用户、1会员用户、2管理员用户
     */
    private Integer userType;

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
     * 昵称
     */
    public String getUsername() {
        return username;
    }

    /**
     * 昵称
     */
    public void setUsername(String username) {
        this.username = username;
    }

    /**
     * 账号
     */
    public String getAccount() {
        return account;
    }

    /**
     * 账号
     */
    public void setAccount(String account) {
        this.account = account;
    }

    /**
     * 密码
     */
    public String getPassword() {
        return password;
    }

    /**
     * 密码
     */
    public void setPassword(String password) {
        this.password = password;
    }

    /**
     * 余额
     */
    public Integer getBalance() {
        return balance;
    }

    /**
     * 余额
     */
    public void setBalance(Integer balance) {
        this.balance = balance;
    }

    /**
     * 秘钥(用来加密可加密的字段)
     */
    public String getUserKey() {
        return userKey;
    }

    /**
     * 秘钥(用来加密可加密的字段)
     */
    public void setUserKey(String userKey) {
        this.userKey = userKey;
    }

    /**
     * 用户类型0普通用户、1会员用户、2管理员用户
     */
    public Integer getUserType() {
        return userType;
    }

    /**
     * 用户类型0普通用户、1会员用户、2管理员用户
     */
    public void setUserType(Integer userType) {
        this.userType = userType;
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
        User other = (User) that;
        return (this.getId() == null ? other.getId() == null : this.getId().equals(other.getId()))
            && (this.getUsername() == null ? other.getUsername() == null : this.getUsername().equals(other.getUsername()))
            && (this.getAccount() == null ? other.getAccount() == null : this.getAccount().equals(other.getAccount()))
            && (this.getPassword() == null ? other.getPassword() == null : this.getPassword().equals(other.getPassword()))
            && (this.getBalance() == null ? other.getBalance() == null : this.getBalance().equals(other.getBalance()))
            && (this.getUserKey() == null ? other.getUserKey() == null : this.getUserKey().equals(other.getUserKey()))
            && (this.getUserType() == null ? other.getUserType() == null : this.getUserType().equals(other.getUserType()))
            && (this.getLogicalDeletion() == null ? other.getLogicalDeletion() == null : this.getLogicalDeletion().equals(other.getLogicalDeletion()));
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((getId() == null) ? 0 : getId().hashCode());
        result = prime * result + ((getUsername() == null) ? 0 : getUsername().hashCode());
        result = prime * result + ((getAccount() == null) ? 0 : getAccount().hashCode());
        result = prime * result + ((getPassword() == null) ? 0 : getPassword().hashCode());
        result = prime * result + ((getBalance() == null) ? 0 : getBalance().hashCode());
        result = prime * result + ((getUserKey() == null) ? 0 : getUserKey().hashCode());
        result = prime * result + ((getUserType() == null) ? 0 : getUserType().hashCode());
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
        sb.append(", username=").append(username);
        sb.append(", account=").append(account);
        sb.append(", password=").append(password);
        sb.append(", balance=").append(balance);
        sb.append(", userKey=").append(userKey);
        sb.append(", userType=").append(userType);
        sb.append(", logicalDeletion=").append(logicalDeletion);
        sb.append(", serialVersionUID=").append(serialVersionUID);
        sb.append("]");
        return sb.toString();
    }
}