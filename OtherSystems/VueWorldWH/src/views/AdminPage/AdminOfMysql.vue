<template>
    <el-tabs class="demo-tabs">

      <el-tab-pane label="视频上传" name="second">视频上传
  
      </el-tab-pane>
      <el-tab-pane label="其他文件上传" name="third">其他文件上传
  
      </el-tab-pane>
      <el-tab-pane label="搜索文件" name="fourth">搜索文件
  
      </el-tab-pane>
    </el-tabs>
  </template>
  
  <script>
  export default {
    name: "AdminOfFile",
  
    data() {
      return {
        //请求url
        httpUrl: "http://127.0.0.1:8080/admin/resour/uploadInmgs",
        fileList: [],   //上传的图片列表
        dataFile: {   //上传图片时附带的参数
          type: '分类',
          date: '时间'
        },
      }
    },
    methods: {
  
      onSubmit() {
        this.$refs.ImageUploadObject.submit();
        // console.log(this.fileList)
      },
  
      onRemove() {
        this.$refs.ImageUploadObject.clearFiles();
      },
  
      uploadPreview() {
  
      },
  
      uploadRemove() {
  
      },
  
      beforeAvatarUpload(rawFile){
        if (rawFile.type !== 'image/jpeg') {
          alert('Avatar picture must be JPG format!');
          return true
        } else if (rawFile.size / 1024 / 1024 > 20) {
          alert('Avatar picture size can not exceed 20MB!')
          return true
        }
        return true
      }
  
  
    }
  }
  </script>
  
  <style scoped>
  
  </style>