<template>

  <el-menu :default-active="activeIndex" class="el-menu-demo" mode="horizontal" @select="handleSelect">
    <el-menu-item index="1">
      <router-link to="/world">首页</router-link>
    </el-menu-item>
    <!-- <el-menu-item index="5">
      <router-link to="/books">书库</router-link>
    </el-menu-item>
    <el-menu-item index="6">
      <router-link to="/index">数据获取</router-link>
    </el-menu-item>
    <el-menu-item index="7">
      <router-link to="/about">Game</router-link>
    </el-menu-item>
   <el-menu-item index="8">
     <router-link to="/wenzhan">文章</router-link>
   </el-menu-item>
   <el-menu-item index="9">
     <router-link to="/text">富文本</router-link>
   </el-menu-item>
    <el-menu-item index="10">
      <router-link to="/movieIndex">Movie</router-link>
    </el-menu-item>
    <el-menu-item index="11">
      <router-link to="/bookint">书籍详细</router-link>
    </el-menu-item>
    <el-menu-item index="12">
      <router-link to="/moviePage">MoviePage</router-link>
    </el-menu-item>
    <el-menu-item index="13">
      <router-link to="/statisticalChart">统计图</router-link>
    </el-menu-item>
    <el-sub-menu index="2">
      <template #title>多级标题</template>
      <el-menu-item index="2-1">item one</el-menu-item>
      <el-sub-menu index="2-2">
        <template #title>item four</template>
        <el-menu-item index="2-2-1">item one</el-menu-item>
      </el-sub-menu>
    </el-sub-menu>
    <el-menu-item index="3" disabled>Info</el-menu-item> -->

    <el-menu-item index="4" style="margin-left: auto">
      <a v-on:click="goToAdminOfResources">个人中心</a>
    </el-menu-item>

  </el-menu>
  <!--  <video src="http://127.0.0.1:8080/file/getVideo?name=Faded_Alan Walke_36615676_MP4UL.mp4" controls="controls"></video>-->
  <router-view></router-view>

</template>

<script>
import {signout, singinx} from "@/api";
// import router from "@/router";

export default {
  name: 'App',
  data() {
    return {
      LoginStatus: false,
    }
  },
  methods: {
    goToAdminOfResources() {
      window.open("/adminOfResources", '_blank');
    },

    //退出登录
    signout: function () {
      localStorage.removeItem("user");
      signout().then(res => {
        console.log(res);
        // alert("退出成功")
      }).catch(err => alert(err));
    },

  },

  created() {
    let token = localStorage.getItem("user");
    if (token != null) {
      let formData = new FormData();
      formData.append('username', token);
      singinx({"account": token}).then(res => {
        console.log(res);
        if (res.data === "true") {
          // alert("已登录");
        } else {
          alert("身份过期!");
        }
      }).catch(err => alert(err));
    }
  },

}
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}
</style>
