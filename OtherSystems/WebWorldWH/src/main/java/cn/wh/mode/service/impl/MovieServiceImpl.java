package cn.wh.mode.service.impl;

import cn.hutool.core.io.FileUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import cn.wh.mode.pojo.Movie;
import cn.wh.mode.service.MovieService;
import cn.wh.mode.mapper.MovieMapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.io.File;
import java.util.List;

import static cn.wh.webmode.config.UsualConfig.StringResourceDirectory;
import static cn.wh.webmode.config.UsualConfig.VideoResources;

/**
 * @author XMZR
 * @description 针对表【movie】的数据库操作Service实现
 * @createDate 2022-05-06 09:41:21
 */
@Service
public class MovieServiceImpl extends ServiceImpl<MovieMapper, Movie>
        implements MovieService {
    @Resource
    MovieMapper movieMapper;

    public Boolean addMovie(Movie movie) {
        return movieMapper.insert(movie) == 1;
    }

    /**
     * 添加一个movie 传入的movie参数 movieName movieSort
     */
    @Override
    public boolean addMovie(File movieFile) {
        Movie movie = new Movie();
        movie.setMovieName(movieFile.getName());
        String url = StringResourceDirectory + VideoResources + "\\" + movie.getMovieName();
        return movieMapper.insert(movie) == 1;
    }

    /**
     * 删除指定id movie
     */
    @Override
    public boolean deleteMovie(Integer movieId) {
        return false;
    }

    /**
     * 更新一个movie的信息
     */
    @Override
    public boolean updateMovie(Movie movie) {
        return false;
    }

    /**
     * 查询所有movie信息
     */
    @Override
    public List<Movie> queryMovieList() {
        return null;
    }

    /**
     * 查询指定id movie信息
     */
    @Override
    public Movie queryMovieOne(Integer movieId) {
        return null;
    }

    /**将目录下的所有视频文件信息入库*/
    public boolean setMovieFileOfData(File file) {
        if (!file.isDirectory()) return false;
        for (File file1 : FileUtil.loopFiles(file)) {
            Movie movie = new Movie();
            movie.setMovieName(file1.getName());
            movie.setMovieUrl(file1.getPath());
            if (movieMapper.insert(movie) != 1) return false;
        }
        return true;
    }

}




