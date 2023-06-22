package com.rsgisai.geohazard.auth.controller;

import com.rsgisai.geohazard.auth.dao.UserInfoDao;
import com.rsgisai.geohazard.auth.entity.UserDetailsVo;
import com.rsgisai.geohazard.auth.exception.UserDetailsException;
import com.rsgisai.geohazard.system.common.R;
import com.rsgisai.geohazard.system.common.UserInfo;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.security.provisioning.JdbcUserDetailsManager;
import org.springframework.web.bind.annotation.*;

/**
 * For administration only
 * if for current user, use UserInfoController
 */
@RestController
@RequestMapping("/user-details")
public class UserDetailsController {

    private final PasswordEncoder passwordEncoder;
    private final JdbcUserDetailsManager jdbcUserDetailsManager;
    private final UserInfoDao userInfoDao;

    public UserDetailsController(JdbcUserDetailsManager jdbcUserDetailsManager, PasswordEncoder passwordEncoder, UserInfoDao userInfoDao) {
        this.jdbcUserDetailsManager = jdbcUserDetailsManager;
        this.passwordEncoder = passwordEncoder;
        this.userInfoDao = userInfoDao;
    }

    @GetMapping
    public R<UserInfo> getSelf(Authentication authentication) {
        User user = (User) authentication.getPrincipal();
        UserInfo result = userInfoDao.selectByUsername(user.getUsername());
        return R.ok(result);
    }

    @PostMapping
    public R<UserDetails> create(UserDetailsVo user) throws UserDetailsException {
        user.setPassword(passwordEncoder.encode(user.getPassword()));
        UserDetails userDetails = user.toUserDetails();
        try {
            jdbcUserDetailsManager.createUser(userDetails);
        } catch (Exception e) {
            throw new UserDetailsException("用户创建失败", e);
        }
        return R.success(userDetails).message("用户创建成功");
    }

    @DeleteMapping
    public R<String> delete(UserDetailsVo user) throws UserDetailsException {
        try {
            jdbcUserDetailsManager.deleteUser(user.getUsername());
        } catch (Exception e) {
            throw new UserDetailsException("delete failed.");
        }
        return R.success("").message("用户" + user.getUsername() + "已删除");
    }

    @PostMapping("/password")
    public R<String> updatePassword(
            @RequestParam("oldPassword") String oldPassword,
            @RequestParam("newPassword") String newPassword
    ) {
        newPassword = passwordEncoder.encode(newPassword);
        jdbcUserDetailsManager.changePassword(oldPassword, newPassword);
        return R.success("修改密码成功");
    }
}
