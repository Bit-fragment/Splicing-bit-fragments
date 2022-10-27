<template>
  <div>
    <h1 style="color: red">Hello index</h1>
    <el-button v-on:click="huoqu()" type="primary" plain>获取数据</el-button>
    <router-view></router-view>
    <el-divider></el-divider>

    <el-table :data="lists" height="500" border style="width: 100%" :key="Math.random()">
      <el-table-column prop="username" label="昵称"></el-table-column>
      <el-table-column prop="account" label="账号"></el-table-column>
      <el-table-column prop="password" label="密码"></el-table-column>
      <el-table-column prop="balance" label="余额"></el-table-column>
      <el-table-column prop="userKey" label="key"></el-table-column>
      <el-table-column prop="userType" label="用户类型"></el-table-column>
      <el-table-column prop="logicalDeletion" label="逻辑删除状态"></el-table-column>
      <el-table-column label="操作">
        <el-dropdown>
          <el-button type="primary">
            More operations
            <el-icon class="el-icon--right">
              <arrow-down/>
            </el-icon>
          </el-button>
          <template #dropdown>
            <el-dropdown-menu>
              <el-dropdown-item>修改资料</el-dropdown-item>
              <el-dropdown-item>管理权限</el-dropdown-item>
              <el-dropdown-item>Action 3</el-dropdown-item>
              <el-dropdown-item>Action 4</el-dropdown-item>
              <el-dropdown-item>Action 5</el-dropdown-item>
            </el-dropdown-menu>
          </template>
        </el-dropdown>
      </el-table-column>
    </el-table>

  </div>

</template>

<script type="text/javascript">
import {huoqu1} from "@/api";

export default {
  name: "IndexW",
  data() {
    return {
      lists: [],
    };
  },

  methods: {
    huoqu: function () {
      huoqu1().then(res => {
        console.log(res);
        if ("0" === JSON.parse(res.data).code) {
          alert("未登录!")
        }else {
          //将后端返回的json字符串转换为json对象
          this.lists = JSON.parse(res.data);
        }
      }).catch(err => alert(err));
    },

  },
}
</script>

<style>

</style>
