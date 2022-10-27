<template>

  <el-button v-on:click="signout()">退出登录</el-button>
  <el-container class="layout-container-demo">
    <el-aside width="200px" style="height: 700px;">
      <el-scrollbar>
        <el-menu :default-openeds="['1']">
          <el-sub-menu index="1">
            <template #title>
              <el-icon>
                <message/>
              </el-icon>
              网站内容
            </template>
            <el-menu-item-group>
              <el-menu-item index="1-1">
                <router-link to="/adminOfArticle">文章管理</router-link>
              </el-menu-item>
              <el-menu-item index="1-2">评论管理</el-menu-item>
            </el-menu-item-group>
          </el-sub-menu>

          <el-sub-menu index="2">
            <template #title>
              <el-icon>
                <icon-menu/>
              </el-icon>
              用户管理
            </template>
            <el-menu-item-group>
              <el-menu-item index="2-1">用户统计</el-menu-item>
              <el-menu-item index="2-2">权限管理</el-menu-item>
            </el-menu-item-group>
          </el-sub-menu>

          <el-sub-menu index="3">
            <template #title>
              <el-icon>
                <setting/>
              </el-icon>
              资源管理
            </template>
            <el-menu-item-group>
              <el-menu-item index="3-1">
                <router-link to="/adminOfCensus">资源统计</router-link>
              </el-menu-item>
              <el-menu-item index="3-2">
                <router-link to="/adminOfFile">上传资源</router-link>
              </el-menu-item>
              <el-menu-item index="3-3">
                <router-link to="/adminOfMysql">MYSQL管理</router-link>
              </el-menu-item>
              <el-menu-item index="3-4">
                <router-link to="/adminOfRedis">Redis管理</router-link>
              </el-menu-item>
            </el-menu-item-group>
          </el-sub-menu>

        </el-menu>
      </el-scrollbar>
    </el-aside>

    <el-container>
      <!--      <el-header>
              <el-input style="width: 400px;"/><el-button>搜索</el-button>
            </el-header>-->
      <el-main>
        <router-view/>
      </el-main>

    </el-container>

  </el-container>
</template>

<script>
import router from "@/router";
import {getLoginStatus, LoginStatus,signout} from "@/api";

export default {
  name: "AdminOfResources",
  data() {
    return {}
  },
  methods: {
    getLoginStatus: function () {
      getLoginStatus().then(res => {
        if (res.data === 'true') {
          console.log("已登陆")
        } else {
          router.push("/singin");
        }
      }).catch(err => console.log(err))
    },

    //退出登录
    signout: function () {
      localStorage.removeItem("user");
      signout().then(res => {
        console.log(res);
        // alert("退出成功")
        router.push("/world");
      }).catch(err => alert(err));
    },

    wenhao: function () {
      alert(this.$root.$data.wenhao())
      alert(LoginStatus);
      // updateLoginStatus(true);
      alert(LoginStatus);
      // alert(getLoginStatusValue);
      // alert(updateLoginStatus(true));
      // alert(getLoginStatusValue);
    }
  },
  // 创建生命周期的第一阶段 beforeCreate
  // 在这个阶段中，所有的属性，方法， 都是不可调用的
  beforeCreate() {
    // console.log(this.info);
    // console.log(this.message);
    // this.show();
  },

  // created 创建阶段,生命周期的第二个阶段, 非常常用
  // 经常在他里面调用methods中的方法，请求服务器
  // 并且，吧请求到的数据转存到data中， 工template模板渲染的时候使用
  // 注意：在create阶段中模板结构还没有被渲染，因此不能操作DOM结构
  created() {
    this.getLoginStatus();
    // console.log('created');
    // let dom = document.querySelector('#dom');
    // console.log(dom); // null 获取不到
  },

  // 渲染之前， 第三个阶段, 获取不到DOM元素，不常用
  beforeMount() {
    // console.log('beforeMount');
    // let dom = document.querySelector('#dom');
    // console.log(dom);
  },

  // 生命周期的第四个阶段, 渲染阶段， 这个阶段可以获取页面中的dom元素了， 比较常用
  mounted() {

    // console.log('mouted');
    // let dom = document.querySelector('#dom');
    // console.log(dom);
  },


  // 5.更新之前阶段 beforeUpdate
  // 当数据发生改变时，就会触发这个函数
  // 这个阶段拿到的是还没有更新完成之前的旧值， 但是页面结构已经完成了
  beforeUpdate() {

  },

  // 6.更新完成阶段 updated
  updated() {

  },

  // 7.销毁前阶段 beforeDestroy,
  // 销毁前所有组件都还保持工作状态，并未完全被销毁
  // beforeDestroy() {
  //   console.log('beforeDestroy');
  // },

  // 8. destroyed 销毁阶段
  // destroyed() {
  //   console.log('destroyed');
  // }

}
</script>

<style scoped>

</style>