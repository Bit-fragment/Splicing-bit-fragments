<template>
  <div>
    账号:<input type="text" v-model="username"><br/>
    密码:<input type="password" v-model="password"><br/>
    <el-button v-on:click="singin()">登录</el-button>
    <el-button v-on:click="fh()">放回上一步</el-button>
  </div>
</template>

<script>
import {singin} from "@/api";
import router from "@/router";

export default {
  name: "SingIn",
  data() {
    return {
      username: "",
      password: "",
      value: "",
    }
  },
  methods: {
    singin: function () {
      singin({account: this.username, password: this.password}).then(res => {

        if ("0" === JSON.parse(res.data).code) {
          this.value = JSON.parse(res.data).key;
          localStorage.setItem("user", this.value);
          // alert("登陆成功");
          router.push("/adminOfResources");
        } else {
          alert("登陆失败");
        }
      }).catch(err => alert(err));

    },

    fh: function () {
      this.$router.go(-1)  // 返回上级操作
    }
  }

}
</script>

<style scoped>

</style>