<?php
/**
 * Created by PhpStorm.
 * User: DELL-XPS
 * Date: 2017/7/20
 * Time: 12:13
 */
class Corporate_Drone {
    private $employeeid;
    private $tiecolor;

    function setEmpoyleeID($employeeid)
    {
        $this->employeeid = $employeeid;
    }
    function getEmployeeID(){
        return $this->employeeid;
    }
    function setTieColor($tiecolor){
        $this->tiecolor = $tiecolor;
    }
    function getTieColor(){
        return $this->tiecolor;
    }
    function __clone()
    {
       $this->tiecolor="blue"; // TODO: Implement __clone() method.
    }
}
//新建对象
$drone1 = new Corporate_Drone();
$drone1->setEmpoyleeID("12345");
$drone1->setTieColor("red");
$drone2 = clone $drone1;
$drone2->setEmpoyleeID("67890");
//输出
printf("Drone1 employeeID:%d<br/>",$drone1->getEmployeeID());
printf("Drone1 tie color:%s<br/>",$drone1->getTieColor());
printf("Drone2 employeeID:%d<br/>",$drone2->getEmployeeID());
printf("Drone1 tie color:%s<br/>",$drone2->getTieColor());
