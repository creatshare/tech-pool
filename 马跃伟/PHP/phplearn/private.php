<?php
/**
 * Created by PhpStorm.
 * User: DELL-XPS
 * Date: 2017/7/20
 * Time: 10:02
 */
class Employee{
    private $name;
    public function setName($name)
    {
        $this->name = $name;
    }

    /**
     * @return mixed
     */
    public function getName()
    {
        return $this->name;
    }
}
$employee = new Employee();
$employee->setName("huabuxiu");
echo $employee->getName();