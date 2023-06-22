package com.rsgisai.geohazard.level.entity.elements_at_risk;

import org.eclipse.emf.ecore.EFactory;
import org.springframework.beans.factory.BeanFactory;
import org.springframework.beans.factory.config.BeanDefinition;
import org.springframework.context.annotation.ClassPathScanningCandidateComponentProvider;
import org.springframework.core.type.filter.AssignableTypeFilter;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * create sub classes object
 *
 * @author tfh, created at 2023-05-26 4:16 PM
 */
public class ElementsAtRiskFineFactory {


    static List<AbstractElementsAtRiskFine> getAllBaseClassObjects() {
        List<AbstractElementsAtRiskFine> instances = new ArrayList<>();

        String packageName = AbstractElementsAtRiskFine.class.getPackage().getName();
        ClassPathScanningCandidateComponentProvider provider =
                new ClassPathScanningCandidateComponentProvider(false);
        provider.addIncludeFilter(new AssignableTypeFilter(AbstractElementsAtRiskFine.class));

        Set<BeanDefinition> beanDefinitions = provider.findCandidateComponents(packageName);
        for (BeanDefinition beanDefinition : beanDefinitions) {
            Class<?> clazz;
            try {
                clazz = Class.forName(beanDefinition.getBeanClassName());
                AbstractElementsAtRiskFine o = (AbstractElementsAtRiskFine) clazz.newInstance();
                instances.add(o);
            } catch (ClassNotFoundException | InstantiationException | IllegalAccessException e) {
                throw new RuntimeException(e);
            }
        }

        return instances;
    }

    public static List<AbstractElementsAtRiskFine> allBaseClassObjects = getAllBaseClassObjects();

    public AbstractElementsAtRiskFine getSubclassObject(ElementsAtRiskFine elementsAtRiskFine) {
        for (AbstractElementsAtRiskFine abstractElementsAtRiskFine : allBaseClassObjects) {
            if (abstractElementsAtRiskFine.getCanonicalName().equals(elementsAtRiskFine.getName())) {
                return abstractElementsAtRiskFine.clone(elementsAtRiskFine);
            }
        }
        throw new RuntimeException("not supported type of elements-at-risk. type:" + elementsAtRiskFine.getName());
    }
}
