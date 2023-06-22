package com.rsgisai.geohazard.system.common;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Map;
import java.util.TreeMap;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class R<T> {
    private static final Integer SUCCESS = 200;
    private static final Integer FAIL = 400;
    private Integer code;
    private String message;
    private T data;
    private Map<String, Object> debug;

    public static <T> R<T> success(T data) {
        R<T> r = new R<>();
        r.code = SUCCESS;
        r.data = data;
        return r;
    }

    /**
     * alias of success()
     */
    public static <T> R<T> ok(T data) {
        return success(data);
    }

    public static <T> R<T> fail(T data, String message) {
        R<T> r = new R<>();
        r.code = FAIL;
        r.message = message;
        r.data = data;
        return r;
    }

    public static <T> R<T> fail(String message) {
        R<T> r = new R<>();
        r.code = FAIL;
        r.message = message;
        return r;
    }

    public static <T> R<T> status(org.springframework.http.HttpStatus status) {
        R<T> r = new R<>();
        r.code = status.value();
        r.message = status.getReasonPhrase();
        return r;
    }

    public R<T> message(String message) {
        this.message = message;
        return this;
    }

    public R<T> data(T data) {
        this.data = data;
        return this;
    }

    public R<T> withData(T data) {
        this.data = data;
        return this;
    }

    public R<T> put(String key, Object value) {
        if (this.debug == null) this.debug = new TreeMap<>();
        this.debug.put(key, value);
        return this;
    }
}
