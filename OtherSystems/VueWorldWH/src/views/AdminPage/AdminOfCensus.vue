<template>
  <table border="1">
    <tr v-for="(item,key) in ImgUrlList" :key="key">
      <td>
        <el-image
            style="width: 480px; height: 270px"
            :lazy="true"
            :src="item"
            :preview-src-list="ImgUrlList"
            :initial-index="key"
            fit="cover"
        />
        <br />
        <el-link v-on:click="gotoImgs(item)" type="warning">{{ item }}</el-link>
      </td>
    </tr>
  </table>
</template>

<script>
import {getImgFileUrlList} from "@/api";

export default {
  name: "AdminOfCensus",
  data() {
    return {
      ImgNameList: [],
      ImgUrlList:[],
    }
  },
  methods: {
    DataFormat(){
      for (let i = 0; i < this.ImgNameList.length; i++) {
        this.ImgUrlList.push('http://127.0.0.1:8080/imgs/'+this.ImgNameList[i])
      }
    },
    gotoImgs(url) {
      window.open(url);
    },
    getImgFileUrlList() {
      getImgFileUrlList().then(res => {
        if ("0" === JSON.parse(res.data).code) {
          this.ImgNameList = JSON.parse(res.data).data;
          this.DataFormat();
        } else {
          alert("没有数据！")
        }
      }).catch(err => {
        console.log(err)
      })
    }
  },
  created() {
    this.getImgFileUrlList();

  }
}
</script>

<style scoped>

</style>