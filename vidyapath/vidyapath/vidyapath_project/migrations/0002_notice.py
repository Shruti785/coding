# Generated by Django 5.1.5 on 2025-01-20 17:50

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('vidyapath_project', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='Notice',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('description', models.TextField()),
                ('created_at', models.DateTimeField(auto_now_add=True)),
            ],
        ),
    ]
