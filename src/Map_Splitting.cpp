#include "Map_Splitting.h"

        std::vector<split_leaf> Map_Splitter::Reverse_Split(std::vector<split_leaf> leaves, int height, int width)
        {
            std::vector<split_leaf> splits = std::vector<split_leaf>();
            int i, j;

            for (long unsigned int k = 0; k < leaves.size(); ++k)
            {
                split_leaf split = leaves[k];
                i = height - (split.i + split.height);
                j = width - (split.j + split.width);
                splits.insert(splits.begin(), split_leaf(i, j, split.height, split.width));
            }
            return splits;
        }

        std::vector<split_leaf> Map_Splitter::VerticalSplit(std::vector<split_leaf> leaves, int min_width)
        {
            std::vector<split_leaf> splits = std::vector<split_leaf>();
            int i1, j1, height1, width1, i2, j2, height2, width2;
            int rand_res;

            for (long unsigned int k = 0; k < leaves.size(); ++k)
            {
                split_leaf leaf = leaves[k];
                if (leaf.width >= (min_width*2))
                {
                    // Если пригоден для разбиения
                    i1 = leaf.i; j1 = leaf.j;  // начальные координаты первого листа

                    rand_res = random(min_width, leaf.width - min_width+1);

                    i2 = leaf.i; j2 = leaf.j+rand_res; // начальные координаты второго листа
                    height1 = leaf.height; height2 = leaf.height; // высота одинаковая
                    width1 = rand_res; width2 = leaf.width - rand_res;

                    // ------- Добавляем новые листы ------- //
                    splits.push_back(split_leaf(i1, j1, height1, width1));
                    splits.push_back(split_leaf(i2, j2, height2, width2));

                } else // если не пригоден для разбиения - то отправляем в новый список
                 splits.push_back(split_leaf(leaf.i, leaf.j, leaf.height, leaf.width));
            }
            return splits;
        }

        std::vector<split_leaf> Map_Splitter::HorizontalSplit(std::vector<split_leaf> leaves, int min_height)
        {
            std::vector<split_leaf> splits = std::vector<split_leaf>();
            int i1, j1, height1, width1, i2, j2, height2, width2;
            int rand_res;

            for (long unsigned int k = 0; k < leaves.size(); ++k)
            {
                split_leaf leaf = leaves[k];
                if (leaf.height >= (min_height*2))
                {

                    // Если пригоден для разбиения
                    i1 = leaf.i; j1 = leaf.j;  // начальные координаты первого листа

                    rand_res = random(min_height, leaf.height - min_height+1);

                    j2 = leaf.j; i2 = leaf.i+rand_res; // начальные координаты второго листа
                    width1 = leaf.width; width2 = leaf.width; // ширина одинаковая
                    height1 = rand_res; height2 = leaf.height - rand_res;

                    // ------- Добавляем новые листы ------- //
                    splits.push_back(split_leaf(i1, j1, height1, width1));
                    splits.push_back(split_leaf(i2, j2, height2, width2));

                } else // если не пригоден для разбиения - то отправляем в новый список
                 splits.push_back(split_leaf(leaf.i, leaf.j, leaf.height, leaf.width));
            }
            return splits;
        }

        // --------------------------------- Разбиение самой карты ---------------------------------------- //
        std::vector<split_leaf> Map_Splitter::Split(int map_height, int map_width, int min_height, int min_width)
        {
            std::vector<split_leaf> splits = std::vector<split_leaf>(); //Создаем массив для хранения листьев
            splits.push_back(split_leaf(0, 0, map_height, map_width)); // заносим первый лист размером со всю карту
            long unsigned int cur_leaf = 1;//присваиваем количество листьев 1
            int series = 0;

            bool vertical = true; // начинаем с вертикального деления

            while (series < 2)
            {
                if (vertical)
                {
                    splits = VerticalSplit(splits, min_width);
                    vertical = false;
                } else
                {
                    splits = HorizontalSplit(splits, min_height);
                    vertical = true;
                }
                if (cur_leaf == splits.size()) series++;
                else cur_leaf = splits.size();
            }

            return splits;
        }
        //--------------------------------------------------------------------------------------------------//
