use geohazard;

alter table sys_user
    modify column update_time datetime default current_timestamp();
