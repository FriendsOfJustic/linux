package com.rsgisai.geohazard.subsystem.service;

import com.rsgisai.geohazard.subsystem.dao.pgsql.InfluenceAreaDao;
import com.rsgisai.geohazard.system.common.entity.InfluenceArea;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

@SpringBootTest
public class InfluenceAreaTest {
    @Autowired
    InfluenceAreaService influenceAreaService;
    @Autowired
    InfluenceAreaDao influenceAreaDao;

    @Test
    void select(){
        List<InfluenceArea> id = influenceAreaService.queryById(1);
        id.forEach(System.out::println);
    }

    // 根据ID进行删除
    @Test
    public void testDelete(){
        int delete = influenceAreaDao.delete(3);
        System.out.println(delete);
    }

    // 插入数据
    @Test
    public void TestInsert(){
        InfluenceArea influenceArea = new InfluenceArea();
        // 构造对象
        influenceArea.setId(6);
        influenceArea.setWorkingAreaId(12L);
        influenceArea.setGeom(null);
        influenceArea.setTergetRegionId(null);
        influenceArea.setArea(35.5);

        // 执行新增操作
        influenceAreaDao.insert(influenceArea);
        //System.out.println(influenceArea.getWorkingAreaId());
    }

    // 更新数据
    @Test
    public void TestUpdate(){
        InfluenceArea influenceArea = new InfluenceArea();
        // 构造对象
        influenceArea.setId(4);
        influenceArea.setWorkingAreaId(2L);
        influenceArea.setGeom(null);
        influenceArea.setTergetRegionId(null);
        influenceArea.setArea(53.5);

        // 执行新增操作
        influenceAreaDao.update(influenceArea);
        //System.out.println(influenceArea.getWorkingAreaId());
    }

    // 根据条件查询
    @Test
    public void TestList(){
        //List<InfluenceArea> influenceAreas= influenceAreaDao.list(2L, 0.0, 60.0);
        List<InfluenceArea> influenceAreas= influenceAreaDao.list(2L, 0.0 ,70.0);
        System.out.println(influenceAreas);
    }


    // 根据ID查询
    @Test
    public void testGetById(){
        InfluenceArea influenceArea = influenceAreaDao.getById(1);
        System.out.println(influenceArea);

    }


}
