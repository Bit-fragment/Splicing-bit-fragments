<template>
  <h2>MOVIE</h2>

  <div>
    <el-divider></el-divider>

<!--
    <p v-for="(item, keey) in srclist" :key="keey">
      <l v-on:click="playing(item)" class="td" >
        <el-row>

          <el-col class="col1">
            <img src="../../assets/fengmian.jpg"
                 style="width: 152px;height: 210px;margin-left: 53px;margin-top: 10px"/>
          </el-col>

          <el-col class="col2">
            <font style="font-weight: bold" color="#87cefa">{{ item}}</font>
          </el-col>

          &lt;!&ndash;
                          <el-col class="col3">
                            <el-row>
                              <el-col class="col2">
                                <font color="#ff8c00">作者</font>:{{ Posts }}
                              </el-col>

                              <el-col class="col2">
                                <font color="#e9967a">简介</font>:{{ Posts }}
                              </el-col>
                            </el-row>
                          </el-col>
          &ndash;&gt;

        </el-row>
      </l>
    </p>
-->

    <el-container direction="vertical" >
      <el-main style="text-align: center;">
        <div>
          <el-input type="text" style="width: 500px"></el-input>
          <el-button>搜索Movie</el-button>
        </div>
        <div style="margin-top: 10px">
          <el-radio-group v-model="radio1" size="large">
            <el-radio-button label="动作" />
            <el-radio-button label="犯罪" />
            <el-radio-button label="科幻" />
            <el-radio-button label="记录" />
          </el-radio-group>
        </div>
      </el-main>
      <!--    头部-->
      <el-main style="width: 1500px;">

          <el-row :gutter="20">
            <el-col :span="4" v-for="(item, keey) in srclist" :key="keey">
              <br />
              <div style="background-color: lightslategrey;height: 300px;width: 240px;">
                <td v-on:click="playing(item)" class="td" >
                  <el-row>

                    <el-col>
                      <img src="../../assets/meizi01.jpg"
                           style="width: 100%;height: 230px;"/>
                    </el-col>

                    <el-col>
                      <font style="font-weight: bold;margin: 0 auto" color="black">{{item}}</font>
                    </el-col>

                  </el-row>
                </td>
              </div>
            </el-col>
          </el-row>

        <el-pagination
            id="yema" background layout="prev, pager, next"
            :total="total"
            v-model:current-page="CurrentPage"
            :pager-count="PagerCount"
            :page-size="PageSize"/>

<!--        <div style="width: 1800px; height: 10px;background-color: #2c3e50"></div>-->

<!--        <table border="1" style="border-spacing: 10px;margin-left: 4%">
          <tr v-for="(Posts, keey) in srclist" :key="keey">
            <td v-on:click="playing(Posts)" class="td">
              <el-row>

                <el-col class="col1">
                  <img src="../../assets/fengmian.jpg"
                       style="width: 152px;height: 210px;margin-left: 53px;margin-top: 10px"/>
                </el-col>

                <el-col class="col2">
                  <font style="font-weight: bold" color="#87cefa">{{ Posts }}</font>
                </el-col>

                &lt;!&ndash;
                                <el-col class="col3">
                                  <el-row>
                                    <el-col class="col2">
                                      <font color="#ff8c00">作者</font>:{{ Posts }}
                                    </el-col>

                                    <el-col class="col2">
                                      <font color="#e9967a">简介</font>:{{ Posts }}
                                    </el-col>
                                  </el-row>
                                </el-col>
                &ndash;&gt;

              </el-row>
            </td>
          </tr>
        </table>-->

<!--        <td>
          <el-card class="box-card" shadow="hover" body-style="text-align:left;width: 100%;padding: 10">
            <template #header>
              <span>文章标题</span>
              <el-button class="button" type="text">查看详细</el-button>
            </template>
            <el-row :gutter="250">

              <el-col :span="5">
                <img src="../assets/tu1.png" style="width: 230px; height: 140px" fit="cover">
              </el-col>

              <el-col :span="17">
                <el-row>
                  <el-col>
                    {{ Posts.neirong }}
                  </el-col>
                  <el-col>
                    <el-divider content-position="left">
                      {{ '作者:' + Posts.zuozhe }}
                      点赞 收藏 留言:94984 浏览:979898987
                    </el-divider>
                  </el-col>
                </el-row>
              </el-col>

            </el-row>
          </el-card>
        </td>-->


      </el-main>

    </el-container>

<!--    <el-divider></el-divider>-->
  </div>

</template>

<script>
// import { ref } from 'vue'
import axios from "axios";

// const radio1 = ref('New York')

export default {
  name: "MoviePage",
  components: {
    // radio1
  },
  methods: {
    ellipsis(value) {
      if (!value) return "";
      if (value.length > 12) {
        return value.slice(0, 12) + "...";
      }
      return value;
    },

    playing(url){
      // let url = JSON.stringify(src);
      this.$router.push({ path: "/moviePlaying", query: { url } });
    },

    bofan: function (url) {
      this.srcpath = "http://127.0.0.1:8080/file/getVideo?name=" + url;
      //eventBus.$emit('eventName', "hello");
    },

  },
  created() {
    this.wenben = this.shuju.concat();
    for (var p = 0; p < this.wenben.length; p++) {
      this.wenben[p].biaoti = this.ellipsis(this.shuju[p].biaoti);
      this.wenben[p].neirong = this.ellipsis(this.shuju[p].neirong);
      this.wenben[p].zuozhe = this.ellipsis(this.shuju[p].zuozhe);
      this.wenben[p].id = this.ellipsis(this.shuju[p].id);
    }

    axios("http://127.0.0.1:8080/file/mp4src").then(res => {
      console.log(res);
      this.srclist = res.data;
    }).catch(err => alert(err));

  },
  data() {
    return {
      //数据总条数
      total: 2000,
      //当前页数
      CurrentPage: 1,
      //页码数量
      PagerCount: 13,
      //每页显示数据条数
      PageSize: 10,

      shuju: [
        {
          biaoti: "很长的书名书名书名书名书名书名书名书名书名书名书名书名书名",
          neirong: "很长的简介简介简介简介简介简介简介简介简介简介简介简介简介",
          zuozhe: "很长的作者名作者名作者名作者名作者名作者名作者名作者名作者名",
          id:"id=64641"
        },
        {
          biaoti: "很长的书名书名书名书名书名书名书名书名书名书名书名书名书名",
          neirong: "很长的简介简介简介简介简介简介简介简介简介简介简介简介简介",
          zuozhe: "很长的作者名作者名作者名作者名作者名作者名作者名作者名作者名",
          id:"id=64641"
        },
        {
          biaoti: "很长的书名书名书名书名书名书名书名书名书名书名书名书名书名",
          neirong: "很长的简介简介简介简介简介简介简介简介简介简介简介简介简介",
          zuozhe: "很长的作者名作者名作者名作者名作者名作者名作者名作者名作者名",
          id:"id=64641"
        },

      ],
      wenben: [],
      srcpath: "",
      srclist: []
    }
  },


}


</script>

<style scoped>
.td {
  width: 260px;
  height: 320px;
}

.col1 {
  height: 230px;
}

.col2 {
  text-align: center;
  height: 30px;
}

.col3 {
  text-align: center;
  height: 60px;
}


</style>